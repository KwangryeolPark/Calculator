#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DECODE_STRING "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqstuvwxyz0123456789"

struct value{
	char String[500];
	char *name;
	unsigned num;
};

int main(void) {
	char String[500], String_simbol[500] = "", String_num[500] = "";
	char *Position_Of_simbols[250];
	char *Position_Of_nums[251];

	struct value Value[500];

	unsigned flag[250];
	unsigned real_num[250];	
	unsigned cnt = 0, length;
	unsigned nValue = 0;
	for(;;) {
		printf("사용할 변수를 입력한 후 초기화 해주세요 : ");
		scanf(" %s", Value[nValue].String);
		Value[nValue].name = strtok(Value[nValue].String, "=");
		Value[nValue].num = atoi(strtok(NULL, "="));
		if(strcmp(Value[nValue].String, "&"))	nValue++;
		else break;
	}

	printf("\n\n식을 입력하세요 : \n"); 

	scanf(" %s", String);
	strcat(String_num, String);
	strcat(String_simbol, String);

	while((cnt == 0) || (Position_Of_simbols[cnt - 1] != NULL)) {
		Position_Of_simbols[cnt] = (cnt == 0) ? strtok(String_simbol, DECODE_STRING) : strtok(NULL, DECODE_STRING);
		if(Position_Of_simbols[cnt] != NULL) {
			if(!strcmp(Position_Of_simbols[cnt], "*"))	flag[cnt] = 11;
			else if(!strcmp(Position_Of_simbols[cnt], "/")) flag[cnt] = 12;
			else if(!strcmp(Position_Of_simbols[cnt], "+")) flag[cnt] = 1;
			else if(!strcmp(Position_Of_simbols[cnt], "-"))flag[cnt] = 2;
		}
		cnt++;
	}

	length = cnt - 1;
	cnt = 0;

	while((cnt == 0) || (Position_Of_nums[cnt - 1] != NULL)) {
		Position_Of_nums[cnt] = (cnt == 0) ? strtok(String_num, "*/+-") : strtok(NULL, "*/+-");
		if(Position_Of_nums[cnt] != NULL) {
			for(int i = nValue; i >= 0; i--) {
				if(!strcmp(Position_Of_nums[cnt], Value[i].name)) {
					real_num[cnt] = Value[i].num;
					break;
				} else real_num[cnt] = atoi(Position_Of_nums[cnt]);
			}
		} cnt++;
	}
	
	for(int i = 0; i < length; i++) {
		if(flag[i] == 11) {
			real_num[i] *= real_num[i+1];
				printf("%d", real_num[i]);
		}
		else if(flag[i] == 12)	real_num[i] /= real_num[i+1];
		else continue;

		for(unsigned cnt = i; cnt <= length - 1; cnt++) {
			flag[cnt] = flag[cnt + 1];
			real_num[cnt + 1] = real_num[cnt + 2];
		}
		i--;
		length--;
	}
	
	for(int i = 0; i < length; i++) {
		if(flag[i] == 1) real_num[i] += real_num[i+1];
		else if(flag[i] == 2)	real_num[i] -= real_num[i+1];
		else continue;

		for(unsigned cnt = i; cnt < length - 1; cnt++) {
			flag[cnt] = flag[cnt + 1];
			real_num[cnt + 1] = real_num[cnt + 2];
		}
		i--;
		length--;
	}
	printf("\n계산 결과는 다음과 같습니다. : %d\n\n", real_num[0]);

	return 0;
} 

