#include<bits/stdc++.h>
using namespace std;
string s[110],ans[110];
bool hang[110],lie[110];
int main()
{
	memset(hang,1,sizeof(hang));
    memset(lie,1,sizeof(lie));
    int h,w,i,j;
    cin >> h >> w;
    for (i = 0;i < h;i++) 
		cin >> s[i];

    for (i = 0;i < h;i++)
    {
        bool all = 1;
        for (j = 0;j < w;j++)
        {
            if (s[i][j] == '#') 
			{
				all = 0;
				break;
			}
		}
        if (all) 
			hang[i] = 0;
    }
    for (i = 0;i < w;i++)
    {
        bool all = 1;
        for (j = 0;j < h;j++)
    	{
            if (s[j][i] == '#') 
			{
				all = 0;
				break;
			}
    	}
		if (all) 
			lie[i]=0;
    }
    for (i = 0;i < h;i++)
    {
        bool out = 0;
        for (j = 0;j < w;j++)
    	{
            if ((hang[i]) && (lie[j])) 
			{
				cout << s[i][j];
				out = 1;
			}
    	}
		if (out) 
			puts("");
    }
    return 0;
}

