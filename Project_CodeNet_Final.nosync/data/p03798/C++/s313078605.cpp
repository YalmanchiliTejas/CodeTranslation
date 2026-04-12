#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int>pa;
map<int,int>mp;
const int N=2e5+100;
int dp[50][500][500];///前n个a有i，b有j的最小花费
int a[50],b[50],c[50];
int inf=0x3f3f3f3f;
string s;
int n;
int slove(int a,int b)
{
    int k;
    if((a==1&&s[0]=='o')||(a==2&&s[0]=='x')) k=b;
    else k=3-b;
    vector<int>ve;
    ve.push_back(a);ve.push_back(b);
    for(int i=1;i<n;i++){
        if(s[i]=='o'){
           if(ve[i]==1) ve.push_back(ve[i-1]);
           else ve.push_back(3-ve[i-1]);
        }
        else {
            if(ve[i]==1) ve.push_back(3-ve[i-1]);
            else ve.push_back(ve[i-1]);
        }
    }
    if(ve[n]==ve[0] && k==ve[n-1]) {
        for(int i=0;i<ve.size()-1;i++){
            if(ve[i]==1) cout<<'S';
            else cout<<'W';
        }
        return 1;
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>s;
    int f=0;
    for(int i=1;i<=2;i++){
        for(int j=1;j<=2;j++){
            f=slove(i,j);
            if(f) break;
        }
        if(f) break;
    }
    if(!f) cout<<-1<<endl;
    return 0;
}
