#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int lli;
const lli mod = 1e9+7;

int main(){
    string t,p;
    cin >> t >> p;
    t = "." + t + ".";
    vector<int> a,b;
    int n=t.length(), m=p.length();
    for(int i=0,j=0; i<m; i++){
        while(j<n and p[i]!=t[j]) j++;
        if(p[i] == t[j]){
            a.push_back(j);
            j++;
        }
    }
    if((int)a.size() < m){
        cout << "no" << endl;
        return 0;
    }

    for(int i=m-1,j=n-1; i>=0; i--){
        while(j>=0 and p[i]!=t[j]) j--;
        if(p[i] == t[j]){
            b.push_back(j);
            j--;
        }
    }
    reverse(b.begin(), b.end());

    if(a == b){
        cout << "yes" << endl;
    }else{
        cout << "no" << endl;
    }
    return 0;
}
