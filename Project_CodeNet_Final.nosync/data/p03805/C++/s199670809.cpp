#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int N,M;
    cin >> N >> M;
    vector<int> a(M);
    vector<int> b(M);
    rep(i,M){
        cin >> a.at(i) >> b.at(i);
    }
    vector<int> num(N);
    rep(i,N){
        num.at(i)=i+1;
    }
    sort(num.begin(),num.end());
    int ans=0;
    bool bflag=false;
    bool aflag=false;
    do{
        if(num.at(0)!=1){
            break;
        }
        aflag=true;
        bflag=false;
        rep(i,N-1){
            bflag=false;
            rep(j,M){
                if((num.at(i)==a.at(j)&&num.at(i+1)==b.at(j))
                ||num.at(i)==b.at(j)&&num.at(i+1)==a.at(j)){
                    bflag=true;
                    break;
                }
            }
            if(bflag){ 
                continue;
            }else{
                aflag=false;
                break;
            }
            
        }
        if(aflag){
            ans++;
        }
    }while(next_permutation(num.begin(),num.end()));

    cout << ans << endl;
}