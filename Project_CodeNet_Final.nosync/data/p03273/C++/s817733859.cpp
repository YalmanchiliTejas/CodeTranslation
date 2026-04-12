#include <iostream>
#include <vector>
#include <string>
using namespace std;

string dots(int n){
    if (n==1)  return ".";
    else  return "."+dots(n-1);
}

int main()
{
    int h,w;
    cin >> h >> w;
    vector<string> v;
    string wdots = dots(w);
    for (int i=0 ; i<h ; i++){
        string s;
        cin >> s;
        if (s != wdots)  v.push_back(s);
    }
    
    for (int i=0 ; i<w ; i++){
        bool f = true;
        for (int j=0 ; j<v.size() ; j++){
            if (v[j][i] == '#'){
                f = false;
                break;
            }
        }
        if (f){
            for (int k=0 ; k<v.size() ; k++){
                v[k][i] = 'n';
            }
        }
    }
    
    for (int i=0 ; i<v.size() ; i++){
        for (int j=0 ; j<w ; j++){
            if (v[i][j] != 'n')  cout << v[i][j];
        }
        cout << endl;
    }
    
    return 0;
}