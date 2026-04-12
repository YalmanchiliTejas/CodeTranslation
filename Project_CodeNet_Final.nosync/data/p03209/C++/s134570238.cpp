#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string>
#include <tuple>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <set>
#include <stack>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <cassert>
using namespace std;
#define LL long long
#define MP(a, b) make_pair(a, b)
#define MMP(a, b, c) make_pair(make_pair(a, b), c)
#define MAX 1000000000
#undef INT_MIN
#undef INT_MAX
#define INT_MIN -2147483648
#define INT_MAX 2147483647
#define LL_MIN -9223372036854775808
#define LL_MAX 9223372036854775807
#define PI 3.14159265359
/*
int main(){
    iostream::sync_with_stdio(false);
    
    int D;
    cin >> D;
    if(D == 22) cout << "Christmas Eve Eve Eve" << endl;
    if(D == 23) cout << "Christmas Eve Eve" << endl;
    if(D == 24) cout << "Christmas Eve" << endl;
    if(D == 25) cout << "Christmas" << endl;
    
    return 0;
}*/

/*
int main(){
    iostream::sync_with_stdio(false);
    
    int N;
    cin >> N;
    int sum = 0;
    int m = 0;
    for(int i=0; i<N; i++){
        int tmp;
        cin >> tmp;
        sum += tmp;
        m = max(m, tmp);
    }
    cout << sum - m/2 << endl;
    
    return 0;
}*/

/*
int main(){
    iostream::sync_with_stdio(false);
    
    int N,K;
    cin >> N >> K;
    int p[100000];
    for(int i=0; i<N; i++) cin >> p[i];
    sort(p, p+N);
    int ans = INT_MAX;
    for(int i=0; i+K-1<N; i++){
        ans = min(ans, p[i+K-1]-p[i]);
    }
    cout << ans << endl;
    return 0;
}
*/

LL s[51],p[51];
LL solve(int now, LL place){
    if(place < 1) return 0;
    if(place >= s[now]) return p[now];
    return solve(now-1, place-1) + solve(0, place-1-s[now-1]) + solve(now-1, place-1-s[now-1]-s[0]);
}

int main(){
    iostream::sync_with_stdio(false);
    
    LL N,X;
    cin >> N >> X;
    s[0] = 1;
    p[0] = 1;
    for(int i=1; i<=N; i++){
        s[i] = 2*s[i-1] + 3;
        p[i] = 2*p[i-1] + 1;
    }
    cout << solve(N,X) << endl;
    
    return 0;
}