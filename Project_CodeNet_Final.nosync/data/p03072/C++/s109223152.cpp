#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, sum=0, max;
    cin >> N;
    vector<int> m(N);

    for (int i = 0; i < N; i++)
    {
        cin>>m.at(i);
    }
    max = m.at(0);
    for (int i = 0; i < N; i++){
        if(m.at(i)<max){

        }
        else if(m.at(i)>=max)
        {
            max = m.at(i);
            sum++;
        }

    }
    
        cout << sum << endl;
}