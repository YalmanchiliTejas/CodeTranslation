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
    int N;
    cin >> N;
    int M=0;
    int ans=0;
    for(int i=0; i<N; i++){
        int H;
        cin >> H;
        if(H>=M){
            ans++;
            M=H;
        }
    }
    cout<<ans<<endl;
    return 0;
}
