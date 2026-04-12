#include <bits/stdc++.h>
#define fr(i,n) for(int i=0;i<n;i++)
#define pb push_back
typedef long long ll;
typedef long double la;
using namespace std;

int main(){
    string s;
    int count_a=0;
    int count_b=0;
    cin >> s;
    fr(i,s.size()){
        if(s[i] == 'A'){
            count_a++;
        }
        if(s[i] == 'B'){
            count_b++;
        }
    }
    if(count_a == 3 || count_b == 3){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
}