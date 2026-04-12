#include<iostream>
#include<string>
using namespace std;
    char S;
int main(){
    cin>>S;
    cout<<(S=='a'||S=='i'||S=='u'||S=='e'||S=='o'?"vowel":"consonant")<<endl;
    return 0;
}