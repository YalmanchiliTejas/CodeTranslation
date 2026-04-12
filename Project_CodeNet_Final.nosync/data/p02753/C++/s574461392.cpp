/*  
    ┬┴┬┴┤(･_├┬┴┬┴ hiding from those WAs
*/

#include <bits/stdc++.h>
using namespace std;

void ngk(){
    string s;
    cin >> s;
    set <int> z;
    for(auto v: s)	z.insert(v);
    if (z.size() == 1)
    	cout << "No";
    else
    	cout << "Yes";
}

int main(int argc, char *argv[]){
    iostream::sync_with_stdio(0);
    int test = 1;
    while(test--){
        ngk();
    }
    return 0;
}