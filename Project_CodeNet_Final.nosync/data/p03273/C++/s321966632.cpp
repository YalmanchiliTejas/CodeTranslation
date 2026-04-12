#include <bits/stdc++.h>
using namespace std;
int main(){
    int h, w, i, f=0, j;
    vector<string> s(101);
    vector<int> retu(101, 0);
    vector <int> gyou(101, 0);
    cin >> h >> w;
    for(i=0;i<h;i++){
        cin >> s[i];
    }
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            if(s[i][j]=='#'){
                retu[j]=1;
                gyou[i]=1;
            }
        }
    }

    for(i=0;i<h;i++){
        f=0;
        for(j=0;j<w;j++){
            if(gyou[i]==1 && retu[j]==1){
                cout << s[i][j];
                f=1;
            }
        }
        if(f==1) cout <<endl;
    }

    return 0;
}