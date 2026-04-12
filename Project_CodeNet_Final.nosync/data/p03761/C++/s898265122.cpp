#include<bits/stdc++.h>
using namespace std;

const int INF = (int)1e9;

int main() {
	int N;
    cin >> N;
    vector<string> S(N);
    for(int i=0; i<N; i++) cin >> S[i];

    map<char,int> m, ms[55];
    for(int i=0; i<N; i++){
        for(int j=0; j<S[i].length(); j++){
            m[S[i][j]]++;
            ms[i][S[i][j]]++;
        }
    }
    vector<char> chs;
    for(auto itr=m.begin(); itr!=m.end(); itr++){
        if((itr->second != 1) || (N==1)) chs.push_back(itr->first);
    }
    map<char,int> ansm;
    for(int k=0; k<chs.size(); k++) ansm[chs[k]]=INF;
    for(int i=0; i<N; i++){
        for(int k=0; k<chs.size(); k++){
            ansm[chs[k]] = min(ansm[chs[k]],ms[i][chs[k]]);
        }
    }

    for(auto itr=ansm.begin(); itr!=ansm.end(); itr++){
        //cout << itr->first <<" "<< itr->second << endl;
        for(int i=0; i<itr->second; i++){
            cout << itr->first;
        }
    }
    cout << endl;

}