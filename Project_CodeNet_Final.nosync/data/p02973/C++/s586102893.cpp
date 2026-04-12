#include <bits/stdc++.h>

using namespace std;

vector<int> v;

int lis(){

    vector<int> pilha;

    for(int i=0; i<v.size(); i++){

        vector<int> :: iterator it = upper_bound(pilha.begin(),pilha.end(),v[i]);

        if(it==pilha.end()){
            pilha.push_back(v[i]);
        }
        else{
            *it=v[i];
        }
    }
    return pilha.size();
}

int main(){

    int n;

    cin >> n;

    for(int i=0; i<n; i++){

        int a;

        cin >> a;

        v.push_back(-a);
    }

    cout << lis();
}
