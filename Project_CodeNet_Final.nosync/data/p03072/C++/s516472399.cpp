#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    int mount[N];

    for(int i = 0; i < N; i++) {
        cin >> mount[i];
    }

    int MAX = mount[0];
    int counter = 0;

    for(int i = 0; i < N; i++) {
        if(MAX <= mount[i]) {
            counter++;
            MAX = mount[i];
        }
    }

    cout << counter << endl;

}