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
 **四位不重複的亂數產生**
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
 **玩家輸入解答並檢查是否合理** 
 ******************************/
 
	do
	{
		a = 0;b = 0,replay = 1;
		
		do
		{
			c1 = 0,c5 = 0;	
			printf("請輸入4位整數以進行遊戲:");
			gets(input);
			len = strlen(input);
			
			
			/*條件一:檢查是否超過四個字元*/
			
			if(len > 4 || len < 4)
			{
				printf("不足四字元或是多過於四字元，");
				c1 = 1;
			}
			
			/*條件二:檢查輸入字元是否包含非數字*/ 
				
			for(c2 = 0;c2 < len;c2++)
			{
				if(input[c2] < 48 || input[c2] > 57)
				{
					printf("內容包含非數字，");
					c1 = 1;
					break;
				} 
			}
			
			/*條件三:檢查輸入字元是否重複*/ 
			
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
			
			/*如果數字重複則印此行*/
			
			if(c5 == 1)
			{
				printf("數字重複，");
			}
			
			/*滿足上述三者條件之一，則印出重新輸入*/
			
			if(c1 == 1)
			{
				printf("請重新輸入...\n");
			}
		}
		while(c1 == 1);
	
/******************** 
 **猜數字的邏輯判斷** 
 ********************/
	
	/*條件一:當數字及位置都對則a+1*/
	
		for(i1 = 0;i1 <= 3;i1++)
		{
			if(input[i1] == ans[i1])
			{
				a++;
			}
		}
		
		printf("%dA",a);
		
	/*條件二:當數字對位置不對則b+1*/
	
	
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
	
	/*條件三:當a=4則出現you win*/
		
		if(a == 4)
		{
			printf("你猜中了!\n");
			printf("請輸入數字以決定是否繼續遊玩[0-離開本遊戲;大於1繼續本遊戲]:");
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

	printf("\n程式結束.....");
	system("pause");
}
