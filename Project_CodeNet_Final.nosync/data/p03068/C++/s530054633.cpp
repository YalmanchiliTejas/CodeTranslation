#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef long long ll;

#define int ll


main(){
    int n;
    string s;
    int k;
    cin >> n >> s >> k;

    for(int i=0;i<n;i++){
        if(s[i]!=s[k-1]) s[i] = '*';
    }

    cout << s << endl;

	return 0;
}
