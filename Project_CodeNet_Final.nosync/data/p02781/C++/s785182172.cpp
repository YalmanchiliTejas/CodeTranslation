#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    string N;
    int K;
    cin >> N >> K;
    int d = N.size();
    ll ans = 0;
    for(int i=0;i<d;i++){
        if(i!=d-1){
            if(K==1){
                ans+=9;
            }
            if(K==2){
                if(i<1) continue;
                ans+=9*9*(i);
            }
            if(K==3){
                if(i<2) continue;
                ans+=9*9*9*((i)*(i-1)/2);
            }
        }else{
            int num = N[0]-'0';
            if(K==1){
                ans += num;
            }
            if(K==2){
                ans += (num-1)*9*(d-1);
                if(d<2) continue;
                int j=1;
                for(;j<d;j++){
                    if(N[j]!='0'){
                        break;
                    }
                    if(j==d-1){
                        cout << ans << endl;
                        return 0;
                    }
                }
                ans+=9*(d-j-1) + (N[j]-'0');
            }
            if(K==3){
                ll tmp = 0;
                if(d<3) continue;
                tmp += (num-1)*9*9*(d-1)*(d-2)/2;
                int a=1;
                for(;a<d;a++){
                    if(N[a]!='0') break;
                    if(a==d-2){
                        cout << ans+tmp << endl;
                        return 0;
                    }
                }
                int num2 = N[a]-'0';
                tmp += (num2-1)*9*(d-a-1);
                tmp += 9*9*(d-a-1)*(d-a-2)/2;
                int b=a+1;
                for(;b<d;b++){
                    if(N[b]!='0') break;
                    if(b==d-1){
                        cout << ans+tmp << endl;
                        return 0;
                    }
                }
                tmp += 9*(d-b-1)+(N[b]-'0');
                ans += tmp;
            }
            
        }
        //cout << "i:" << i << " ans:" << ans << endl;
    }
    cout << ans << endl;
    return 0;
}