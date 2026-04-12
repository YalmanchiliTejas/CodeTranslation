#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <math.h>
#include <string>
using namespace std;

int c[26], tmp[26];

int main()
{
    int n;
    cin >> n;
    fill(c, c+26, -1);
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        fill(tmp, tmp+26, 0);
        for(int j=0; j<s.size(); j++){
            tmp[s[j]-'a']++;
        }
        for(int j=0; j<26; j++){
            if(c[j]==-1){
                c[j]=tmp[j];
                tmp[j]=0;
            }else{
                c[j]=min(c[j], tmp[j]);
            }
        }
    }
    for(int i=0; i<26; i++){
        for(int j=0; j<c[i]; j++){
            cout << char('a'+i);
        }
    }
    
    return 0;
}
