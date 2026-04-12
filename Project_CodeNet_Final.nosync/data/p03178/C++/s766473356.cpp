#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
vector <long long> num;
string a;
long long k,res1,res2;
long long f[10005][200][3];
long long call(int pos,long long remain,long long status)
{
    if(pos==num.size())
    {
        if (remain==0)
            return 1;
        return 0;
    }
    if(f[pos][remain][status]!=-1)
        return f[pos][remain][status]%MOD;
    long long res=0,limit;
    if(status==0)
        limit=num[pos];
    else
        limit=9;
    for(int i=0; i<=limit; i++)
    {
        int cur_status=status;
        int cur_remain=(remain+i)%k;
        if(status==0 && i<limit)
            cur_status=1;
        res+=call(pos+1,cur_remain,cur_status);
    }
    return f[pos][remain][status]=res%MOD;
}
void preprocess(string x)
{
    num.clear();
    int p=0;
    while (p<=x.size()-1)
    {
        num.push_back(x[p]-'0');
        p++;
    }
    memset(f,-1,sizeof(f));
}
int main ()
{
    cin>>a;
    cin>>k;
    preprocess(a);
    res1=call(0,0,0);
    cout<<(res1-1+MOD)%MOD<<endl;
}
