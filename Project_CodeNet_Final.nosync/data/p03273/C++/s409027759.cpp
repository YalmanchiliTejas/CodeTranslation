#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector <string> sv;
    string s;
    int ns,sl;
    cin>>ns>>sl;
    for(int i=0;i<ns;i++){
        cin>>s;
        sv.push_back(s);
    }
    for(int i=0;i<sv.size();i++){
        int re=0;
        for(int i2=0;i2<sv[i].length();i2++){
            if(sv[i][i2]=='.'){
                re++;
            }
        }
        if(re==sv[i].length()){
            sv.erase(sv.begin()+i,sv.begin()+i+1);
            i--;
        }
    }
    for(int i=0;i<sv[0].length();i++){
        int re=0;
        for(int i2=0;i2<sv.size();i2++){
            if(sv[i2][i]=='.'){
                re++;
            }
        }
        if(re==sv.size()){
            for(int i3=0;i3<sv.size();i3++){
                sv[i3].erase(i,1);
            }
            i--;
        }
    }
    for(int i=0;i<sv.size();i++){
        cout<<sv[i]<<endl;
    }
    return 0;
}
