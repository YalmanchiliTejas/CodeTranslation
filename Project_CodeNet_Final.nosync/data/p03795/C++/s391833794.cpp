#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    int price = 800;
    int bonas = 200;
    int x,y;
    x = N * price;
    y = ( (N - N % 15) / 15 ) * bonas;
    int ans = x - y;
    cout << ans << endl;
}
