#include<cstdio>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<cstdlib>
#include<iomanip>
#include<queue>
#include<set>

using namespace std;

void Solution()
{
    int n, flag = 0;
    
    while(cin>>n, n)
    {
        if(flag)
        {
            cout<<endl;
        }
        
        int a, b, c, z[100], tmp;
        
        string s[100], tmp2;
        
        for(int i = 0; i < n; i++)
        {
            cin>>s[i]>>a>>b>>c;
            
            z[i] = a * 3 + c;
        }
        
        for(int i = 0; i < n - 1; i++)
        {
            for(int j = n - 1; j > i; j--)
            {
                if(z[j] > z[j - 1])
                {
                    tmp = z[j];
                    z[j] = z[j - 1];
                    z[j - 1] = tmp;
                    
                    /*swap the team name and score*/
 
                    tmp2 = s[j];
                    s[j] = s[j - 1];
                    s[j - 1] = tmp2;
                }
            }
        }
        
        for(int i = 0; i < n; i++)
        {
            cout<<s[i]<<","<<z[i]<<endl;
        }
        
        flag = 1;
    }
}

int main()
{
    Solution();
    return 0;
}