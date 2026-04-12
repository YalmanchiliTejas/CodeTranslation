#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
int main(){
    int n;
    cin>>n;
    vector<string> S(n);
    rep(i,n){
        cin>>S[i];
    }
    string ans="";
    //各アルファベットが各Siで最低何個使われてるかを格納する
    int a = (int)'a';//最初のアルファベット
    vector<pair<char,int>> cnt(26);
    rep(i,26){
        cnt.at(i)={(char)i+a,100000};//全部INFで初期化
    }
    int tmp=0;
    rep2(i,a,a+26){
        //アルファベットiが
        rep(j,n){
            tmp=0;
            //Siの中に
            rep(k,S[j].size()){
                //何個あるか
                if(S[j].at(k)==(char)i){
                    tmp++;
                }
            }
            cnt.at(i-a).second=min(cnt.at(i-a).second,tmp);
        }
    }
    //aから順にcnt個出力
    rep(i,cnt.size()){
        rep(j,cnt.at(i).second){
            ans+=(int)cnt.at(i).first;
        }
    }
    rep(i,26){
        // cout << "lt:"<<cnt.at(i).first<<" cnt:" << cnt.at(i).second<<endl;

    }
    cout << ans << endl;

    return 0;
}