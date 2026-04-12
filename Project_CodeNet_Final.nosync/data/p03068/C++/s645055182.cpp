#include<iostream>
using namespace std;

int main(){
    int n,k;
    cin>>n;
    char s[n];
    char nice;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    cin>>k;

    nice = s[k-1];

    for(int i=0;i<n;i++){
        if(s[i]!= nice)s[i]='*';
    }

    for(int i=0;i<n;i++){
        cout<<s[i];
    }
    cout<<endl;



    return 0;
}
