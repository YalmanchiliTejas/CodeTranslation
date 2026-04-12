#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; (i) < (n); (i)++)
using namespace std;

int cb(int n, int k){
    if(n < k)
        return 0;
    if(k == 0){
        return 1;
    }else if(k == 1){
        return n;
    }else if(k == 2){
        return n*(n-1)/2;
    }else{
        return n*(n-1)*(n-2)/6;
    }
}

int nine(int k){
    int ans = 1;
    if(k<0)
        return 0;
    else{
        REP(i, k)
            ans *= 9;
        return ans;
    }
    
}

int main()
{
    string Nmoji, temp;
    int N, K, index;
    long ans;
    cin >> Nmoji;
    cin >> K;
    ans = 0;
    N = Nmoji.length();
    index = 0;
    REP(i, N){
        if((N-i) < (K-index))
            break;
        if(K == index){
            ans++;
            break;
        }
        if(Nmoji[i] == '0')
            continue;
        if(i < N-1){
                ans += cb(N-1-i, K- index) * nine(K-index);
                ans += cb(N-1-i, K-1-index) * nine(K-index-1) * ((int)(Nmoji[i] - '0') - 1);
                index++;
        }else{
            ans += (int)(Nmoji[N-1]-'0');
        }
    }
    cout << ans << endl;
    return 0;
}

