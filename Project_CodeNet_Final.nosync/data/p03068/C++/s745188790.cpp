#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<math.h>

#define rep(i,a,n) for(int (i)=(a);(i)<(n);(i)++)
#define rrep(i,a,n) for(int (i)=(a);(i)>=(n);(i)--)

#define INF 100000000
#define MOD 1000000009

typedef  long long ll;

using namespace std;

double euclid_distance(double a,double b){
    return sqrt(a*a+b*b);
}

int gcd(long long int a,long long int b){
    long long int r;
    if(a < b){
        int tmp;
        tmp = a;
        a = b;
        b = tmp;
    }
    while(r != 0){
        r = a % b;
        a = b;
        b = r;
    }
    return r;
}

void Integer_factorization(long long int b,long long int n){
    long long int a = 2;
    long long int count = 0;
    long long int ans = 1;
    long long int ndash = n;
    if(b == 1) cout << n << endl;
    else{
    while(ndash >= a*a){
        if(n % a  == 0){
            count++;
            n/=a;

        if(count % b == 0){
            ans *= a;
        }
        }else{a++;count = 0;}
    }

    cout<<  ans << endl;
    }
}

void ys(){
    cout << "Yes" << endl;
}

void yb(){
    cout << "YES" << endl;
}

void ns(){
    cout << "No" << endl;
}

void nb(){
    cout << "NO" << endl;
}


void solve(void){
   int n;
   string s;
   int k;
   cin >> n >> s >> k;
   char key = s[k-1];
   rep(i,0,n){
       if(s[i] != key){
           s[i] = '*';
       }
   }
   cout << s <<endl;

}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}