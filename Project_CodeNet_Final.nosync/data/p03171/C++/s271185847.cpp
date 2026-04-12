#include<bits/stdc++.h>
//#include<stdint-gcc.h>

using namespace std;

map<int,int> mp;

bool sortcol(const vector<int>& v1, const vector<int>& v2 )
{
    return v1[1] < v2[1];
}

long long int a[3000];
long long int dp[3000][3000][2];
bool checker[3000][3000][2];

long long int recursion(int start, int ender, int turn)
{
    if(start>ender)
        return 0;
    if(checker[start][ender][turn]==true)
        return dp[start][ender][turn];
    if(turn==1)
    {
        dp[start][ender][turn]=max(recursion(start+1,ender,0)+a[start],recursion(start,ender-1,0)+a[ender]);
        checker[start][ender][turn]=true;
    }
    else
    {
        dp[start][ender][turn]=min(recursion(start+1,ender,1)-a[start],recursion(start,ender-1,1)-a[ender]);
        checker[start][ender][turn]=true;
    }
    return dp[start][ender][turn];
}

int main()
{
    int test=1;
    //cin>>test;
    while(test--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                for(int k=0;k<2;++k)
                {
                    checker[i][j][k]=false;
                    dp[i][j][k]=0;
                }
            }
        }
        for(int i=0;i<n;++i)
            cin>>a[i];
        cout<<recursion(0,n-1,1);
    }

    return 0;
}

