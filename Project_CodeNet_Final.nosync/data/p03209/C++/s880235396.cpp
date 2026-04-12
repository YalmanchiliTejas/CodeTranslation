#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
long long l[51];
long long p[51];
long long n, x;

long long calc(long long d, long long pos){
    if(d == 1){
        if(x - pos <= 4) return x - pos - 1;
        else return 3;
    }
    if(pos + 1 >= x) return 0;
    else if(pos + 1 + l[d - 1] >= x) return calc(d - 1, pos + 1);
    else if(pos + 2 + l[d - 1] == x) return (p[d] + 1) / 2;
    else if(pos + 2 + 2 * l[d - 1] >= x) return calc(d - 1, pos + 2 + l[d - 1]) + p[d - 1] + 1;
    else return p[d];
}

int main(){
    long long ans = 0;
    cin >> n >> x;
    l[0] = p[0] = 1;
    for(int i = 1; i <=50; i++){
        l[i] = 2 * l[i - 1] + 3;
        p[i] = 2 * p[i - 1] + 1;
    }
    ans = calc(n, 0);
    cout << ans << endl;
    return 0;
}
