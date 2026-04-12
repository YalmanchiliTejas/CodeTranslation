#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(long i = 0; i < n; i++)
#define erep(i, n) for(long i = 1; i <= n; i++)

int main(){long n;
cin >> n;
vector<string> s(n + 1);
erep(i, n) cin >> s.at(i);

vector<long> x(33);
vector<long> y(33);
erep(i, 32) y.at(i) = 51;

long k;
erep(i, n){
    rep(j, s.at(i).size()){
        k = 1;
        for(char t = 'a'; t <= 'z'; t++){
            if(s.at(i).at(j) == t){
                x.at(k)++;
            }
            k++;
        }
    }
    erep(u, 31){
        y.at(u) = min(x.at(u), y.at(u));
        x.at(u) = 0;
    }
}
k = 1;
for(char t = 'a'; t <= 'z'; t++){
    for(long i = 1; i <= y.at(k); i++){
        cout << t;
    }
    k++;
}
cout << endl;


// cout << ans << endl;
return 0;
}


