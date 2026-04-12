#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
using ll = long long;

int main() {
    ll n,a,top,end;
    cin >> n;
    vector<ll> b(n);
    if(n%2==0){
        top=n/2;
        end=n/2+1;
        for(int i=0;i<n;i++){
               cin >> a;
               if(i%2==0){
                      b[top-1]=a;
                      top--;
               }
               else{
                   b[end-1]=a;
                   end++;
               }
        }
    }
    else{
        top=n/2;
        end=(n+1)/2;
        for(int i=0;i<n;i++){
            cin >> a;
            if(i%2==0){
                b[end-1]=a;
                end++;
            }
            else{
                b[top-1]=a;
                top--;
            }
        }
    }
    for(int i=n-1;i>=0;i--){
        cout << b[i] << ' ';
    }
	return 0;
}