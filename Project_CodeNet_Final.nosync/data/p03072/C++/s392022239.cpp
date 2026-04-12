#include <bits/stdc++.h>
using namespace std;

int main()
{
    //input
    int N,max;
    int count = 1;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++)
    {
        cin >> H[i];
    }
    max = H[0];
    //calc
    for (int i = 1; i < N; i++)
    {
        if(H[i]>=max){
            count++;
            max = H[i];
        }
    }
    cout << count << endl;
    return 0;
}