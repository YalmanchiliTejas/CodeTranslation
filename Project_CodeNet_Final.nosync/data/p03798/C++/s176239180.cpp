#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define pb push_back
#define P pair<int,int>
#define vp vector<P>
#define PP pair<int,P>
#define vpp vector<PP>
#define fi first
#define se second
#define INF 1e9
#define MOD 1000000007
#define REP(i,n) for(int i=0;i<n;i++)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define all(x) (x).begin(),(x).end()
void output(vi ans){
    REP(i,ans.size()){
        cout<<(ans[i]?'S':'W');
    }cout<<endl;
}
int main(){
    int n;
    cin>>n;
    string st;
    cin>>st;
    vi ans(n);
    REP(p,2){
        REP(q,2){
            ans[0]=p;
            ans[1]=q;
            FOR(i,1,n-1){
                if((ans[i]&&st[i]=='o')||(!ans[i]&&st[i]=='x')){
                    ans[i+1]=ans[i-1];
                }else{
                    ans[i+1]=!ans[i-1];
                }
            }
            int a;
            if((ans[0]&&st[0]=='o')||(!ans[0]&&st[0]=='x')){
                a=ans[1];
            }else{
                a=!ans[1];
            }
            int b;
            if((ans.back()&&st.back()=='o')||(!ans.back()&&st.back()=='x')){
                b=ans[n-2];
            }else{
                b=!ans[n-2];
            }
            if(ans.back()==a&&ans[0]==b){
                output(ans);
                return 0;
            }
        }
    }
    cout<<-1<<endl;
    return 0;
}