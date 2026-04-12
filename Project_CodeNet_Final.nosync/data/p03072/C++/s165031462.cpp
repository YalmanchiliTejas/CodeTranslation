#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> h(N);
    for(int i = 0; i < N; i++)
    {
        cin >> h[i];
    }

    int count = 1;
    int max = h[0];
    for(int i = 1; i < N; i++)
    {
        if(max > h[i]){
            continue;
        }
        max = h[i];
        count++;
    }

    cout << count << endl;
    
    
}