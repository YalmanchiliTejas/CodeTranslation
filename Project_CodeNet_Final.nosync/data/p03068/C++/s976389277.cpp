#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
#include<utility>
#include<cmath>
#include<cstring>
#include<map>
using namespace std;
 
int main(){
 
int N,K;
string S,ans;
cin>>N>>S>>K;

for(int i = 0; i < N; i++){
    if(S[i] == S[K-1]){
        ans += S[i];
    }else{
        ans += "*";
    }
}

cout << ans << endl;

}