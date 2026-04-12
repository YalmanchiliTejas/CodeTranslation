#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
#define INF 999999999
#define int64 long long
#define rep(i, n) for(int i = 1; i <= (int)(n); i++)
int gcd(int a,int b){return b?gcd(b,a%b):a;}


int main(){
    int N, K;
    cin >> N;
    string S;
    cin >> S;
    cin >> K;
    char c = S[K-1];
    for(int i=0; i<S.length(); ++i){
        if (S[i] != c){
            cout << "*";
        }
        else cout << S[i];
    }
    return 0;
}