#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	char input[50];
	char ans[4];
	int r1 = 0,r2 = 0,same = 0,temp = 0;
	int len = 0,c1 = 0,c2 = 0,c3 = 0,c4 = 0;
	int i1 = 0,i2 = 0,i3 = 0,a = 0,b = 0;
	int replay = 1,c5 = 0,replay_1 = 0;
	
/************************
 **�|�줣���ƪ��üƲ���**
 ************************/
do
{
	
	for(r1 = 0;r1 <= 3;r1++)									
	{
		do
		{
			same = 0;
			temp = rand() % 10;
			ans[r1] = temp + '0';
			for(r2 = 0;r2 < r1;r2++)
			{
				if(ans[r1] == ans[r2])
				same = 1;
			}	
		}
	while(same == 1);
	}
	
/******************************
 **���a��J�ѵ����ˬd�O�_�X�z** 
 ******************************/
 
	do
	{
		a = 0;b = 0,replay = 1;
		
		do
		{
			c1 = 0,c5 = 0;	
			printf("�п�J4���ƥH�i��C��:");
			gets(input);
			len = strlen(input);
			
			
			/*����@:�ˬd�O�_�W�L�|�Ӧr��*/
			
			if(len > 4 || len < 4)
			{
				printf("�����|�r���άO�h�L��|�r���A");
				c1 = 1;
			}
			
			/*����G:�ˬd��J�r���O�_�]�t�D�Ʀr*/ 
				
			for(c2 = 0;c2 < len;c2++)
			{
				if(input[c2] < 48 || input[c2] > 57)
				{
					printf("���e�]�t�D�Ʀr�A");
					c1 = 1;
					break;
				} 
			}
			
			/*����T:�ˬd��J�r���O�_����*/ 
			
			for(c3 = 0;c3 <= 3;c3++)
			{
				for(c4 = 0;c4 < c3;c4++)
				{
					if(input[c3] == input[c4])
					{
						c1 = 1;
						c5 = 1;
						break;
					}
				}
			}
			
			/*�p�G�Ʀr���ƫh�L����*/
			
			if(c5 == 1)
			{
				printf("�Ʀr���ơA");
			}
			
			/*�����W�z�T�̱��󤧤@�A�h�L�X���s��J*/
			
			if(c1 == 1)
			{
				printf("�Э��s��J...\n");
			}
		}
		while(c1 == 1);
	
/******************** 
 **�q�Ʀr���޿�P�_** 
 ********************/
	
	/*����@:��Ʀr�Φ�m����ha+1*/
	
		for(i1 = 0;i1 <= 3;i1++)
		{
			if(input[i1] == ans[i1])
			{
				a++;
			}
		}
		
		printf("%dA",a);
		
	/*����G:��Ʀr���m����hb+1*/
	
	
		for(i2 = 0;i2 <= 3;i2++)
		{
			for(i3 = 0;i3 <= 3;i3++)
			{
				if(input[i2] == ans[i3]&&i2 != i3)
				{
					b++;
				}
			}
		}
	
		printf("%dB\n",b++);
	
	/*����T:��a=4�h�X�{you win*/
		
		if(a == 4)
		{
			printf("�A�q���F!\n");
			printf("�п�J�Ʀr�H�M�w�O�_�~��C��[0-���}���C��;�j��1�~�򥻹C��]:");
			scanf("%d",&replay_1);
			if(replay_1 >= 1)
			{
				replay = 0;
			}
			else
			{
				replay = 0;
			}
		}	
	}
	while(replay >= 1);
}
while(replay_1 >= 1);

	printf("\n�{������.....");
	system("pause");
}
