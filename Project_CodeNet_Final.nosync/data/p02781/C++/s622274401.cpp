#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1000000007;

int main(){
    string S;
    int K;
    cin>>S>>K;
    int X=S.size();
    int Y=S.at(0)-'0';
    if(K==1){
        cout<<Y+9*(X-1)<<endl;
        return 0;
    }
    if(K==2){
        ll Ans=0;
        Ans+=(X-1)*(X-2)/2*9*9;
        Ans+=(Y-1)*9*(X-1);
      	for(int i=1; i<X; i++){
            int N=S.at(i)-'0';
         
            if(N!=0){
                    Ans+=N;
                    Ans+=9*(X-i-1);
              break;
            }
        }
        cout<<Ans<<endl;
    }
    bool O=true;
    if(K==3){
        ll Ans=0;
        Ans+=(X-1)*(X-2)*(X-3)/6*9*9*9;
        Ans+=(Y-1)*(X-1)*(X-2)/2*9*9;
        for(int i=1; i<X; i++){
          	int N=S.at(i)-'0';
            if(!O){
                  if(N!=0){
                      Ans+=N;
                      Ans+=9*(X-i-1);
                break;
              }
            }
            if(O){
                if(N!=0){
                    Ans+=(N-1)*9*(X-i-1);
                  	Ans+=9*9*(X-i-1)*(X-i-2)/2;
                    O=false;
                }
            }
        }
        cout<<Ans<<endl;
    }

}