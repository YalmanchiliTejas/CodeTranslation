#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define lli long long int
#define ll long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;

int main(){
    int N;
    int a[20];
    cin >> N;
    for(int i = 0; i < N; i++){
      cin >> a[i];
    }
    int b = 0;
    int c = 0;
    for(int i = 0; i < N; i++){
      if(b <= a[i]){
        c++;
        b = a[i];
      }
    }
    cout << c;
    return 0;
}
