#include <bits/stdc++.h>
#define REP(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
using P = pair<int,int>;
typedef long long ll;
const ll mod = 1e9+7;
#define all(x) (x).begin(),(x).end()

template<class T> inline void chmin(T& a, T b) {
    if (a > b) {
        a = b;
    }
}

template<class T> inline void chmax(T& a, T b) {
    if (a < b) {
        a = b;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::cout<<std::fixed<<std::setprecision(10);
    string S;
    int K,beforesum = 0,N,lastsum = 0,beforesuma = 0;
    cin >> S >> K;
    N = S.size();
    if(K == 1){
        cout << 9*N-9+S[0]-48<< "\n";
    }else if(K == 2){
        if(N == 1){
            cout <<0<< "\n";
        }else{
            beforesum = 9*9*(N-1)*(N-2)/2+(S[0]-49)*(N-1)*9;
            int oka = 0;
            REP(i,N-1){
                if(S[i+1] != '0'){
                    oka = i+1;
                    break;
                }
            }
            if(oka != 0){
                lastsum = (N-oka-1)*9+S[oka] - 48;
            }
            cout <<beforesum + lastsum<< "\n";
        }
    }else if(K == 3){
        if(N < 3){
            cout <<0<< "\n";
        }else{
            beforesum = (N-3)*(N-2)*(N-1)*9*9*9/6+(S[0]-49)*(N-1)*(N-2)/2*9*9;
            int oka = 0;
            REP(i,N-1){
                if(S[i+1] != '0'){
                    oka = i+1;
                    break;
                }
            }
            if(oka != 0){
                string Sa;
                Sa = S.substr(oka,N-oka);
                int Na = Sa.size();
                if(Na == 1){
                    cout <<0<< "\n";
                }else{
                    beforesuma = 9*9*(Na-1)*(Na-2)/2+(Sa[0]-49)*(Na-1)*9;
                    int okaa = 0;
                    REP(i,Na-1){
                        if(Sa[i+1] != '0'){
                            okaa = i+1;
                            break;
                        }
                    }
                    if(okaa != 0){
                        lastsum = (Na-okaa-1)*9+Sa[okaa] - 48;
                    }
                    lastsum = beforesuma + lastsum;
                }
            }
            cout <<beforesum + lastsum<< "\n";
        }
    }
}