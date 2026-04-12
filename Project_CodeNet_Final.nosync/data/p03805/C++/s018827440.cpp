#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, count=0;
    cin >> n >> m;
    vector<int> a(m), b(m);
    for(int i=0; i<m; i++){
        cin >> a.at(i) >> b.at(i);
    }
    vector<int> p(n);
    for(int i=0; i<n; i++) p.at(i) = i+1;
    do{
        bool B;
        for(int i=0; i<n-1; i++){
            B=false;
            for(int j=0; j<m; j++){
                if((a.at(j) == p.at(i) && b.at(j) == p.at(i+1)) || (a.at(j) == p.at(i+1) && b.at(j) == p.at(i))){
                    B=true;
                    break;
                } 
            }
            if(!B) break;
        }
        if(B) count++;
    }while(next_permutation(p.begin()+1, p.end()));
    cout << count << endl;
}