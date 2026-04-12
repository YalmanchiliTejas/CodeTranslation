#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    vector<int> Hi;

    cin >> N;

    Hi.resize(N);

    for(int i=0; i<N; i++){
        cin >> Hi.at(i);
    }

    int count = 1;
    for(int i=1; i<N; i++){

        bool enable = true;
        
        for(int j=0; j<i; j++){
            
            if(Hi.at(i)<Hi.at(j)){
                enable = false;
                break;
            }
        }

        if(enable){
            count++;
        }
    }

    cout << count << endl;

    return 0;
}