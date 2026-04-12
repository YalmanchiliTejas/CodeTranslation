#include "bits/stdc++.h"
#include <math.h>
#include <time.h>
using namespace std;
const long long mod = 1000000007;
#define dump(x)                             \
    if (dbg) {                              \
        cout << #x << " = " << (x) << endl; \
    }
bool dbg = false;
long long gcd(long long a, long long b){
   if (a % b == 0)
   {
       return(b);
   }
   else
   {
       return(gcd(b, a % b));
   }
}
long long lcm(long long a, long long b){
   return (a / gcd(a, b))* b;
}
//---------------------------------------------------------------------------------------------------
/*ここからいじる*/
//---------------------------------------------------------------------------------------------------

void solve(){
}
int main(){
    string n;
    int N;
    int k;
    cin >> n;
    cin >> k;
    N = n.size();//何桁あるか
    long long ans = 0;
    if(k == 1){
        ans += (N - 1) * 9;
        ans += (n.at(0) - '0');
        cout << ans << endl;
    }
    if(k == 2){
        for(int i = 1; i < N - 1; i++){
            ans += (9 * (i * 9));//1桁目は何か、2桁目をどこに入れるか、2桁目は何か
        }
        ans += (n.at(0) - '1') * (N - 1) * 9;
        bool ck = false;
        for(int i = 1; i < N; i++){
            if(!ck){
            ans += (n.at(i) - '0');  
                if(n.at(i) != '0'){
                    ck = true;
                }
            }
            else{
                ans += 9;
            }
        }
        if(ans < 0){
            ans = 0;
        }
        cout << ans << endl;
    }
    if(k == 3){
        for(int i = 2; i < N - 1; i++){
            ans += (i * (i - 1) * 9 * 9 * 9 / 2);//1桁目は何か、2桁目をどこに入れるか、2桁目は何か、3桁目をどこに入れるか、3桁目は何か
        }
        ans += (n.at(0) - '1') * (N - 1) * 9 * (N - 2) * 9 / 2;
        int M = N - 1;
        for(int j = 1; j < M; j++){
            if(n.at(j) == '0'){
                continue;
            }
        for(int i = 1; i < M - j; i++){
            ans += (9 * (i * 9));//1桁目は何か、2桁目をどこに入れるか、2桁目は何か
        }
        ans += (n.at(j) - '1') * (M - 1) * 9;
        bool ck = false;
        for(int i = j; i < M; i++){
            if(!ck){
            ans += (n.at(i + 1) - '0');  
                if(n.at(i + 1) != '0'){
                    ck = true;
                }
            }
            else{
                ans += 9;
            }
        }
        break;
        }
        if(ans < 0){
            ans = 0;
        }
        cout << ans << endl;

    }
    return 0;
}

