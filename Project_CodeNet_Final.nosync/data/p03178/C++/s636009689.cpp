#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

/*
98765432109876543210
58
*/
int sz;
string k;
int D;
vector<vector<vector<int> > >dp;
int countofDig(int pos,int moderatedsum,int tb){
    //cout<<pos<<" "<<moderatedsum<<" "<<tb<<"\n";
    if(pos>=k.size()-1){
        int lmt = tb==1 ? k[pos]-'0' : 9;
        int cnt=0;
        for(int i=0;i<=lmt;i++){
            if(i%D == moderatedsum){
                cnt++;
            }
        }
        return cnt;
    }
    if(dp[pos][moderatedsum][tb]!=-1){
        return dp[pos][moderatedsum][tb];
    }
    int d = k[pos]-'0';
    long long cnt=0;
    if(tb==1){
        for(int i=0;i<d;i++){
            cnt += countofDig(pos+1,(D+moderatedsum-(i%D))%D,0);
            cnt %=mod;
        }
        cnt += countofDig(pos+1,(D+moderatedsum-(d%D))%D,1);
        cnt %=mod;
    }else{
        for(int i=0;i<=9;i++){
            cnt += countofDig(pos+1,(D+moderatedsum-(i%D))%D,0);
            cnt %=mod;
        }
    }
    return dp[pos][moderatedsum][tb] =cnt;
}
void solve(){
   cin>>k>>D;
   sz = k.size();
   dp.resize(sz,vector<vector<int> >(D,vector<int>(2,-1)));
   cout<< (mod + countofDig(0,0,1) -1)%mod<<"\n";

}

int main(){
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cout.sync_with_stdio(0);

    cout.precision(10);
    int t=1;//cin>>t;
    while(t--){

        solve();
    }
    return 0;
}
