#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    string s;
    int n;
    int m;
    cin>>n;
    cin>>s;
    cin>>m;

    for(int i=0;i<n;i++){

        if(s[i]==s[m-1]){
          cout<<s[i];
        }else{
            cout<<'*';
        }
    }
    printf("\n");
    //cout << "Hello world!" << endl;
    return 0;
}