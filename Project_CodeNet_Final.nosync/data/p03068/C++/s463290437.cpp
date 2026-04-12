#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <iomanip>
#include <functional>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <cmath>
#include <cctype>
#include <cstdio>
#define ll long long
#define INF 1e+9
#define MOD 1000000007
using namespace std;


int main(){
    int N,K;
    string S;
    cin >> N >> S >> K;
    for(int i=0; i<N; i++){
        if(S[i]!=S[K-1]){
            cout<<"*";
        }else{
            cout<<S[i];
        }
    }
    cout<<endl;
    return 0;
}
