#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<map>

typedef long long ll;
using namespace std;

int main(){
    int n;
    string s;
    int k;
    cin >> n >> s >> k;
    for(int i=0;i<n;i++){
        if(s[i]!=s[k-1]){
            s[i]='*';
        }
    }
    cout << s << endl;
}