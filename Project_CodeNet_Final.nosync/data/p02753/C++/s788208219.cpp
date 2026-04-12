    #include <iostream>
    #include <string>
    using namespace std;

    int main(){
        string s;
        cin>>s;

        int a=0;
        int b=0;
        if(s[0]=='A'){
            a=1;
        }else if(s[0]=='B'){
            b=1;
        }

        if(s[1]=='A'){
            a=1;
        }else if(s[1]=='B'){
            b=1;
        }

        if(s[2]=='A'){
            a=1;
        }else if(s[2]=='B'){
            b=1;
        }

        if(a==1&&b==1){
            cout<<"Yes";
        }else{
            cout<<"No";
        }
        return 0;
    }