#include <bits/stdc++.h>
using namespace std;

#define print(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl; 
int main()
{
    int N, M;
    cin >> N >> M;
    if (N == M){
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}
