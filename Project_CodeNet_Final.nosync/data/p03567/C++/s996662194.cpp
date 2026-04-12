#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char const *argv[])
{
    string str;
    getline(cin,str);
    for(int i=0;i<str.length()-1;i++){
        if(str.at(i)=='A'&&str.at(i+1)=='C'){
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
}