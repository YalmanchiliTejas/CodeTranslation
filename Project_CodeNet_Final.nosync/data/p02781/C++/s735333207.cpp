#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector> 
#include<limits>
#include<numeric>
#include<type_traits>
#include<math.h>
#include<fstream>
#include<set>
#include<queue>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7; 

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define out(str) cout << str << endl
#define ALL(a) (a).begin(),(a).end()
#define INF_INT (1<<30)
#define INF_LL (1ll<<62)

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

ll K,ans=0;
string S;

int main(){
    cin>>S>>K;
    if(K==1){
        ans+=S[0]-'0';
        ans+=9*(S.size()-1);
    }
    else if(K==2){
        ans+=(S.size()-1)*(S.size()-2)/2*9*9;
        ans+=(S[0]-'0'-1)*(S.size()-1)*9;
        repi(i,1,S.size()){
            if(S[i]!='0'){
                ans+=S[i]-'0'+(S.size()-i-1)*9;
                break;
            }
        }
    }
    else{
        ans+=(S.size()-1)*(S.size()-2)*(S.size()-3)/6*9*9*9;
        ans+=(S[0]-'0'-1)*(S.size()-1)*(S.size()-2)/2*9*9;
        repi(i,1,S.size()-1){
            if(S[i]!='0'){
                repi(j,i+1,S.size()){
                    if(S[j]!='0'){
                        ans+=(S[i]-'0'-1)*(S.size()-i-1)*9+S[j]-'0'+(S.size()-j-1)*9;
                        break;
                    }
                }
                ans+=(S.size()-i-1)*(S.size()-i-2)/2*9*9;
                break;
            }
        }
    }
    out(ans);
}