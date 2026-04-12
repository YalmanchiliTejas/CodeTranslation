#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    int c;

    if (a < b) {
        a+=b; b=a-b; a-=b;
    }

    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }

    return a;
}

int main(void){
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        bool judge = 0;
        for(int j = 0; j < i; j++){
            if(h[i] < h[j]) judge = 1;
        }
        if(judge == 0) ans += 1;
    }
    cout << ans << endl;

}