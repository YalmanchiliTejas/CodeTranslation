#include<iostream>
#include<string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int N;
    string S;
    int K;
    cin >> N >> S >> K;
    char c;
    c = S[K-1];
    for (int i = 0; i < N; i++)
    {
        if(S[i] != c)
        {
            S[i] = '*';
        }
    }
    cout << S << endl;
}