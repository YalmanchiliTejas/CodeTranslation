#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    for(int i=0;i<n;i++){
        cin >> s[i];
    }
    
    vector<char> c;
    for(int i=0;i<s.at(0).size();i++){
        c.push_back(s.at(0).at(i));
    }
    
    for(int i=0;i<n;i++){
        if(c.size()==0){
            break;
        }
        string t=s.at(i);
        for(int j=0;j<c.size();j++){
            bool judge=true;
            for(int k=0;k<t.size();k++){
                if(c.at(j)==t.at(k)){
                    judge=false;
                    t.erase(t.begin()+k);
                    k--;
                    break;
                }
            }
            if(judge){
                c.erase(c.begin()+j);
                j--;
            }
        }
    }
    
    if(c.size()!=0){
        sort(c.begin(),c.end());
        for(int i=0;i<c.size();i++){
            cout << c.at(i);
        }
        cout << endl;
        return 0;
    }
    cout << endl;
    return 0;
}

