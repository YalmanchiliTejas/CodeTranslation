#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;
    int a[200000];
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    for(int i = 0; i < N; i++){
        if(N - 2*i > 0) cout << a[N - 2*i-1] << ' ';
        else{
            cout << a[N-1-2*(N-i-1)-1];
            if(i != N-1) cout << ' ';
            else cout << endl;
        }
    }
}