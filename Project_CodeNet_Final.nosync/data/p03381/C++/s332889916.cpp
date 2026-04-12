#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    int a[N], b[N];
    for(int i = 0; i < N; i++){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a, a+N);
    for(int i = 0; i < N; i++){
        if(b[i] <= a[N/2-1]) cout << a[N/2] << endl;
        else cout << a[N/2-1] << endl;
    }
    
    return 0;
}