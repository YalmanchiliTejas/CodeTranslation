#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<string> S(N);

    for(int i=0;i<N;i++){
        cin >> S[i];
    }

    vector<int> min_count(26, 100);

    for(int i=0;i<N;i++){
        vector<int> count(26);
        //cout << S[i] << " "<< S[i].size()<< endl;
        for(int j=0; j<S[i].size(); j++){
            int idx = S[i][j] - 'a';
            //cout << S[i][j] << endl;
            count[idx]++;
        }
        for (int k=0;k<26;k++){
            //cout << char(k+'a') << " "<< count[k]<< endl;
            min_count[k] = min(min_count[k], count[k]);
        }
    }

    for (int k=0;k<26;k++){
        for(int i=0;i<min_count[k]; i++){
            cout << char(k+'a');
        }
    }
    cout << endl;
    

    //cout << cntmax << endl;
    return 0;
}