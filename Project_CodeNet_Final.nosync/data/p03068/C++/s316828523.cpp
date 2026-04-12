#include<iostream>
#include<cstring>
#include<math.h>
#include<algorithm>

using namespace std;


int main(){

    long long n=0, k=0;
    string s;

    cin >> n >> s >> k;

    for(int i=0;i<n;i++){
        if(s[i] != s[k-1])s[i] = '*';
    }



    cout << s << endl;
/*    if(){
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
*/
}
