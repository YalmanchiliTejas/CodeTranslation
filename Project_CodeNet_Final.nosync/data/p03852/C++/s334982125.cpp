#include<bits/stdc++.h>
using namespace std;

template <class T1, class T2>
using dict = std::unordered_map<T1, T2>;

int main(){
    char c;
    cin >> c;
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') cout<<"vowel"<<endl;
    else cout<<"consonant"<<endl;
}