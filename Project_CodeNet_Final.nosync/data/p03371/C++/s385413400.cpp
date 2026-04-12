#include <bits/stdc++.h>
using namespace std;
//#define MOD 100000007
long long N;
long long M;
int k;
using Graph = vector<vector<long long>>;
vector<int> color(100000,0);
vector<bool> used(100000,false);
//vector<bool> ans(100000,false);

vector<int> dx = {-1,0,1,0};
vector<int> dy = {0,-1,0,1};
int ans = 0;

int solve(int a,int b)
{
    int ans = 0;
    for(int i=0;i<a;i++)
    {
        for(int j=i+1;j<a;j++)
        {
            for(int k=j+1;k<a;k++)
            {
                if(i+j+k+3 == b)
                {
                    ans++;
                }
            }
        }
    }
    return ans;
}
int main()
{
    int a,b,c,x,y;
    cin >> a>>b>>c>>x>>y;
    
    // x==a+c/2 y = b+c/2
    int i,j,k;
    
    long long ans = LONG_LONG_MAX;
    for(int r=0;r<200001;r++)
    {
        int p=x-r/2;
        int q=y-r/2;
        if(p<0 && q<0)
        {
            break;
        }
        
        long long temp = a*max(p,0) + b * max(q,0) + c*r;
        ans = min(temp,ans);
        if(ans == temp)
        {
            i = p;
            j = q;
            k=r;
        }
        
    }
    
    
    
    cout << ans << endl;
    
    return 0;
}