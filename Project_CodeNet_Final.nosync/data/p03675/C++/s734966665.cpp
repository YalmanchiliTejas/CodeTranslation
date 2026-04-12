#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(a<b) swap(a, b);
    if(b==0) return a;
    return gcd(b, a%b);
}

int h, w;
int arr[100000];
vector<string> v;
int cnt=0;
int main() {
    int n; cin >> n;
    vector<int> v;
    for(int i=0; i<n; ++i){
        int a; cin >> a;
        v.push_back(a);
       
    }
    if(n%2==0){
        for(int i=n-1; i>=0; i-=2){
            cout << v[i] << " ";
        }
        for(int i=0; i<n; i+=2){
            cout << v[i] << " ";
        }
        cout << endl;
    }else{
        for(int i=n-1; i>=0; i-=2){
            cout << v[i] << " ";
        }
        for(int i=1; i<n; i+=2){
            cout << v[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
