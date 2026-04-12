#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <set>
#include <cmath>
#include <array>
#include <bitset>
#include <stdio.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<n+1;i++)

ll solve(string N,int K){
    if(N.size()<K) return 0;
    if(K==1){
        return (N.size()-1)*9 + atoi(N.substr(0,1).c_str());
    }else if(K==2){
        int hoge = atoi(N.substr(0,1).c_str());
        ll ans = ((N.size()-1)*(N.size()-2))/2 * 81 + (hoge-1)*(N.size()-1)*9;
        Rep(i,N.size()){
            if(N[i] != '0'){
                ans += solve(N.substr(i,N.size()-i),1);
                break;
            }
        }
        return ans;
    }else{
        int hoge = atoi(N.substr(0,1).c_str());
        ll ans = ((N.size()-1)*(N.size()-2)*(N.size()-3))/6 *729 + (hoge-1)*((N.size()-1)*(N.size()-2))/2 * 81;
        Rep(i,N.size()){
            if(N[i] != '0'){
                ans += solve(N.substr(i,N.size()-i),2);
                break;
            }
        }
        return ans;
    }
}

int main(){
    string N;
    int K;
    cin>>N;
    cin>>K;
    cout<<solve(N,K);
    return 0;
}