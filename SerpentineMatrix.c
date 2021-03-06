#include <stdio.h>
#include <stdlib.h>

int main()
{
	int size;
	int** arr;
	int y = 0, x = 0, num = 1;
	printf("请输入矩阵大小！！！：");
	scanf_s("%d", &size);
	//初始化数组
	arr = (int **)malloc(sizeof(int *) * size);
	for (int i = 0; i < size; i++) {
		arr[i] = (int *)malloc(sizeof(int) * size);
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			arr[i][j] = 0;
		}
	}
	//填充上三角和对角线
	for (int i = 0; i < size; i++) {
		if (i % 2 == 0) {
			x = i;
			y = 0;
		}
		else{
			y = i;
			x = 0;
		}
		for (int j = 0; j <= i; j++) {
			arr[x][y] = num;
			num++;
			if (i % 2 == 0) {
				x--;
				y++;
			}
			else {
				y--;
				x++;
			}
		}
	}
	//填充下三角
	for (int i = 0; i < size - 1; i++) {
		if (i % 2 == 0) {
			x = size - 1;
			y = i + 1;
		}
		else {
			y = size - 1;
			x = i + 1;
		}
		for (int j = size - 1; j > i; j--) {
			arr[x][y] = num;
			num++;
			if (i % 2 == 0) {
				x--;
				y++;
			}
			else {
				y--;
				x++;
			}
		}
		
	}
	//输出矩阵
	for (int i = 0; i < size; i++) {
		printf("\r\n");
		for (int j = 0; j < size; j++) {
			printf("%d\t",arr[i][j]);
		}
	}
	//释放内存
	for (int i = 0; i < size; i++)
		free(arr[i]);
	free(arr);
}
