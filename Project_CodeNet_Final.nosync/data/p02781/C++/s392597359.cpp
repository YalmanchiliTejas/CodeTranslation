#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <queue>
#include <vector>
#include <set>
using namespace std;
const int maxn = 2e6+10;
typedef pair<int,int> pii;
typedef long long ll;

string s;int K;
ll sum = 0;
ll C[1000][1000];
void initC(int N){
    C[1][1] = 1;
    for(int i = 0;i<=N;i++) C[i][0] = 1;
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=i;j++){
            C[i][j] = C[i-1][j]+C[i-1][j-1];
        }
    }
}
ll ksm(ll a,ll b){
    ll res = 1;
    while(b){
        if(b&1) res *= a;
        a*=a;
        b>>=1;
    }
    return res;
}

void judge(){
    ll cnt = 0,n = 0;
    for(int i = 1;i<=s.length()-1;i++) n = n*10+s[i]-'0';
    for(int i = 1;i<=n;i++){
        int t = i,coun = 0;
        while(t){
            if(t%10 != 0) coun++;
            t/=10;
        }
        if(K == coun) cnt++;

    }
    cout<<"judge "<<cnt<<endl;
}
int main(){
    initC(110);
    cin>>s>>K;
    s.insert(s.begin(),'0');
    int len = s.length()-1;
    if(K>len){
        puts("0"); return 0;
    }
    if(len>K) sum += C[len-1][K]*ksm(9,K);
    if(K == 3){
        sum += (s[1]-'1')*C[len-1][2]*ksm(9,2);
        for(int i = 2;i<=len;i++){
            if(s[i] == '0') continue;
            sum += (s[i] - '1') * C[len-i][1] * ksm(9, 1);
            for (int j = i + 1; j <=len; j++) {
                 if(s[j] == '0') continue;
                 sum += s[j] - '0';
                 sum += C[len-j][1]*9;
                 break;
            }
            if(len-i>=2) sum += C[len-i][2] * ksm(9,2);
            break;
        }
    }
    else if(K == 2){
        sum += (s[1]-'1')*C[len-1][1]*ksm(9,1);
        for(int j = 2;j<=len;j++){
            if(s[j] == '0') continue;
            sum += s[j]-'0';
            if(len-j>=1) sum += C[len-j][1]*9;
            break;
        }
    }else{
        sum += s[1]-'0';
    }
//    judge();
    cout<<sum<<endl;



    return 0;
}