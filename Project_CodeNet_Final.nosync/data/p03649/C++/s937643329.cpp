#include <bits/stdc++.h>
using namespace std;

long long int N, a[55], o, A, B, i;

int main(){
    scanf("%lld", &N);
    for(; i < N; ++i){
        scanf("%lld", a + i);
    }
    sort(a, a + N, greater<long long>());
    //for(i = 0; i < N; ++i)cout << a[i] << " ";
    //cout << endl;
    for(i = 1; i < N; ++i){
        o = (a[i - 1] - a[i]) / (N + 1);
        A += o * i;
        //cout << A << " (" << o << ") ";
        //cout << a[i - 1] - o * N << " : " << a[i] + o * i << endl;
        for(int j = 0; j < i; ++j){
            a[j] -= o * (N + 1);
        }
        //for(int j = 0; j < N; ++j){
        //    cout << a[j] << " ";
        //}
        //cout << endl;
    }
    o = *min_element(a, a + N);
    for(i = 0; i < N; ++i)a[i] -= o;
    B = A;
    B += o;
    //for(i = 0; i < N; ++i)cout << a[i] << " ";
    //cout << endl;
    //cout << B << endl;
    for(i = 0; i < N; ++i){
        a[i] += (B - 1) % N + 1;
    }
    B -= (B - 1) % N + 1;
    while(*max_element(a, a + N) >= N){
        o = max_element(a, a + N) - a;
        //for(i = 0; i < N; ++i)cout << a[i] << " ";
        //cout << endl;
        for(i = 0; i < N; ++i){
            a[i] += (i == o) ? -N : 1;
        }
        ++A;
    }
    //for(i = 0; i < N; ++i)cout << a[i] << " ";
    //cout << endl;
    /*A += (B - N) * N;
    for(i = 0; i < N; ++i){
        a[i] += N;
    }
    while(*max_element(a, a + N) >= N){
        o = max_element(a, a + N) - a;
        for(i = 0; i < N; ++i)cout << a[i] << " ";
        cout << endl;
        for(i = 0; i < N; ++i){
            a[i] += (i == o) ? -N : 1;
        }
        ++A;
    }*/
    cout << A + B * N << endl;//*/
    return 0;
}
