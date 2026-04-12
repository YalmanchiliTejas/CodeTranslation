#include<iostream>
#include<set>

using namespace std;

set<char> hoge(){

    set<char> left;
    string L="qwertasdfgzxcvb";
    for(int i=0; i<L.size(); i++){
        left.insert(L[i]);
    }
    return left;
}

int main(){


    set<char> left=hoge();

    while(1){
        string s;
        cin>> s;
        if(s=="#") break;

        int L=1, R=0;
        int pre;
        int cnt=0;
        for(int i=0; i<s.size(); i++){
            if(i>0){
                if(pre xor left.count(s[i])) cnt++;
            }
            pre=left.count(s[i]);
        }

        cout<< cnt<< endl;

    }

    return 0;
}