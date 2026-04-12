#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    int maxHeight = 0;
    int answer = 0;
    for(int i = 0; i < N; i++)
    {
        int height;
        cin >> height;
        if(maxHeight <= height){
            answer++;
            maxHeight = height;
        }
        
    }
    cout << answer << endl;
    return 0;
}
