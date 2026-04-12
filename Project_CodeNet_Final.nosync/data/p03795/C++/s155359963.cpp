#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, count=0;
    cin >> N;
    for (int i=1; i<=N; i++){
        count+=800;
        if (i%15==0) count-=200;
    }
    cout << count << endl;
}
