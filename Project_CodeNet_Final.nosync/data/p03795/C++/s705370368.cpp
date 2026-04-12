#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
int main(){
    int N;
    cin >> N;
    int a = 800 * N;
    int b = (N / 15) * 200;
    cout << a - b << endl;
    return 0; 
}