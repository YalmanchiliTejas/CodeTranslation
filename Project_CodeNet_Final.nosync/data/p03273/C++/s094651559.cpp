#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int h,w;cin>>h>>w;
    vector<string> a(h);
    vector<string> tmp;
    for(int i=0;i<h;i++){
        cin>>a[i];
        bool is_w = true;
        for(int j=0;j<w;j++){
            if(a[i][j]=='#'){
                is_w = false;
                break;
            }
        }
        if(!is_w)tmp.push_back(a[i]);
    }
    vector<string> ret(tmp.size());
    for(int j=0;j<w;j++){
        bool is_w = true;
        for(int i=0;i<tmp.size();i++){
            if(tmp[i][j]=='#'){
                is_w = false;
                break;
            }
        }
        if(!is_w){
            for(int i=0;i<tmp.size();i++){
                ret[i]+=tmp[i][j];
            }
        }
    }
    for(auto s:ret)cout << s << endl;
    return 0;
}
