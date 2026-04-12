#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
using namespace std;
const int INF = 1001001001;
typedef long long int ll;
#define rep(i, n) for (int(i) = 0; (i) < (n); (i)++)
#define re0 return 0
#include<string.h>
int npr(int n , int r){//nPr
    r = n - r;
    int sum = 1;
    int i;
    for (i=n;i>=r+1;i--)sum*=i;
    return sum;
}
int gcd(int a, int b) {//最大公約数
    if (b==0) return a;
    else return gcd(b, a%b);
}
int lcm(int a, int b) {//最小公倍数
    return a * b / gcd(a, b);
}
int digsum(int n) {//桁和
    int res = 0;
    while(n > 0) {
        //res += n%10;
        //　↑をres++;にすれば桁数
         res++;
        n /= 10;
    }
    return res;
}
bool isPrime(int x){//素数判定
    if(x==1)return 0;
    if(x==2)return 1;
    if(x%2==0)return 0;
    for(int i=3;i*i<=x;i++)if(x%i==0)return 0;
    return 1;
}
/*bit全探索
for (int bit = 0; bit < (1<<N); ++bit) {
}
if (bit & (1 << i)) {
}
*/


int main(void){
    int x; 
    cin >> x;
    if(x>=30)cout << "Yes" <<endl;
    else cout << "No" <<endl;
    return 0;
}


