#include<bits/stdc++.h>
using namespace std;

#define ED return 0;
#define UP(a,b) ((a+(b-1))/b)
#define SORT(vec) sort(vec.begin(),vec.end());
#define DOUBLECHANGE(count) cout << setprecision(count);
#define REV(vec) reverse(vec.begin(),vec.end());
#define ipow(x,y) long(pow(x,y))
const long long int mod = 1000000007;
unsigned long long int gcd(unsigned long long int a, unsigned long long int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> vec (N);
    for(int i = 0;i < N;i++){
        cin >> vec.at(i);
    }

    for(int i = N-1;i > -1;i -= 2){
        cout << vec.at(i) << " ";
    }
    for(int i = N % 2;i < N;i += 2){
        cout << vec.at(i) << " ";
    }
    cout << endl;
}
