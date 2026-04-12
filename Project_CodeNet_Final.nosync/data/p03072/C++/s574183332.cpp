#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector <int> H(N);

    for(int i = 0; i < N; i++)
        cin >> H[i];
    int count = 0;
    int max_hight = 0;
    for(int i = 0; i < N; i++)
    {
        if(max_hight <= H[i])
        {
            count++;
            max_hight = H[i];
        }
    }

    cout << count << endl;
    return 0;  

}