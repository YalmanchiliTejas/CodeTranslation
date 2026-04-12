/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
            佛祖保佑       永无BUG
*/
#include<stdio.h>
#define re register
const int maxn=1e5+5;
int n,num[maxn];
char s[maxn];
int main()
{
	scanf("%d%s",&n,s);
	for(re int i=0;i<=1;++i)
	{
		for(re int j=0;j<=1;++j)
		{
			num[0]=i,num[1]=j;
			for(re int k=2;k<n;++k)
				num[k]=(s[k-1]=='x'^num[k-2]^num[k-1]);
			int t0=num[n-1]^num[1]^num[0]^(s[0]=='x');
			int tn=num[0]^num[n-2]^num[n-1]^(s[n-1]=='x');
			if(t0==0&&tn==0)
			{
				for(re int i=0;i<n;++i)
					if(num[i]==0) putchar('S');
					else putchar('W');
				printf("\n");
				return 0; 
			}
		}
	}
	printf("-1");
	return 0;
}