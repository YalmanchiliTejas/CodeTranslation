#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>

using namespace std;

typedef long long in;

int main(){
    char c;
    cin >> c;
    vector<char> v;
    v.push_back('a');
    v.push_back('e');
    v.push_back('i');
    v.push_back('o');
    v.push_back('u');
    for(int i=0;i<v.size();i++){
        if(v[i]==c){
            cout << "vowel"<<endl;
            return 0;
        }
    }
    cout << "consonant"<<endl;
    return 0;

}
