/*  .　　∧_∧
   　（ ´・ω・)
   　//＼￣￣旦＼
   ／/ ※ ＼＿＿＿＼
   ＼＼ 　※ 　※ 　※ ヽ
   　 ＼ヽ-＿_＿--＿__ヽ*/

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a); i<(b); i++)
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define sort(v,n) sort(v,v+n);
#define vsort(v) sort(v.begin(),v.end());
#define vvsort(v) sort(v.begin(),v.end(),greater<int>());
#define ll long long
#define pb(a) push_back(a)
#define fi first
#define se second
#define inf 999999999
using namespace std;
typedef pair<int,int> p;
typedef pair<ll,ll> lp;
typedef priority_queue<int> pq;
typedef priority_queue<int,vector<int>,greater<int> > rpq;
bool is_uruu(int y) {
        return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0);
}
const ll MOD=1e9+7;
const double PI=acos(-1.0);
//-------------------------------------------------------------------------------------------------------------------------------------------//
int main(){
        int n;
        string s;
        cin>>n;
        cin>>s;
        for(int j=0; j<4; j++) {
                int sw[n+3];
                string ans="";
                if(j==0) {
                        ans="WW";
                        sw[0]=0;
                        sw[1]=0;
                }else if(j==1) {
                        ans="WS";
                        sw[0]=0;
                        sw[1]=1;
                }else if(j==2) {
                        ans="SW";
                        sw[0]=1;
                        sw[1]=0;
                }else if(j==3) {
                        ans="SS";
                        sw[0]=1;
                        sw[1]=1;
                }
                for(int i=1; i<n-1; i++) {
                        if(s[i]=='o') {
                                if((sw[i-1]+sw[i])%2==0) {
                                        sw[i+1]=1;
                                        ans+='S';
                                }else{
                                        sw[i+1]=0;
                                        ans+='W';
                                }
                        }else{
                                if((sw[i-1]+sw[i])%2==0) {
                                        sw[i+1]=0;
                                        ans+='W';
                                }else{
                                        sw[i+1]=1;
                                        ans+='S';
                                }
                        }
                }
                if((sw[n-2]+sw[n-1]+sw[0]+(s[n-1]=='o'))%2==0 && (sw[n-1]+sw[0]+sw[1]+(s[0]=='o'))%2==0) {
                        cout<<ans<<endl;
                        return 0;
                }
        }
        cout<< -1<<endl;
}
