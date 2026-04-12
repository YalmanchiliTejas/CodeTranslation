//

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / __gcd(a, b) * b
#define range(a) (a).begin(),(a).end()
const int inf = 2147483647;

int main (){
    string S;cin >> S;
    cout << (S=="BBB"||S=="AAA" ? "No" : "Yes") << endl;
    return 0;
}