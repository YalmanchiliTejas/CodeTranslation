# include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    string str; cin>>str;
    int len=str.length(); bool found =false ;
    for (int i = 0; (i < len-1 && found==false); ++i)
    {
        if(str[i]=='A' && str[i+1]=='C'){   found=true;  }
    }

    if(found==true){cout<<"Yes";}
    else {cout<<"No";}
}