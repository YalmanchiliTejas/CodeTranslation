#include <bits/stdc++.h>

using namespace std;

int main()
{
    int h,w;
    cin >> h >> w;
    vector<string> a(h);
    for(int i=0;i<h;i++) cin >> a[i];
    
    for(int i=0;i<a.size();i++){
        if(a[i].find('#')==string::npos){
            a.erase(a.begin()+i);
            i--;
        }
    }

    for(int i=0;i<w;i++){
        for(int j=0;j<a.size();j++){
            if(a[j][i]=='#') break;
            if(j==a.size()-1){
                for(int k=0;k<a.size();k++){
                    a[k].erase(a[k].begin()+i);
                }
                i--;
                w--;
            }
        }
    }

    for(int i=0;i<a.size();i++){
        cout << a[i] << endl;
    }
}