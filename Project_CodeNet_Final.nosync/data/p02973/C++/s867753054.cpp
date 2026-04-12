#include<bits/stdc++.h>
using namespace std;
int N;
int main() {
    cin >> N;
    int a[N];
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    vector<int> b;
    b.push_back(a[N-1]);
    for (int i = 1; i < N; i++)
    {
        if(a[N-1-i] >= b[b.size()-1]) b.push_back(a[N-1-i]);
        else{
            auto c = upper_bound(b.begin(), b.end(), a[N-1-i]);
            b[c - b.begin()] = a[N-1-i];
        }
    }

    cout << b.size() << endl;
}