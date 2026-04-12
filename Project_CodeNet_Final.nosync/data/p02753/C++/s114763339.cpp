    #include<iostream>
    using namespace std;
     
    int main(){
      string n;cin>>n;
      int a=0,b=0;
      for(int i=0; i<3; i++){
        if(n[i]=='A')a++;
        else b++;
      }
      if(b==2 && a==1 || b==1 && a==2)cout<<"Yes"<<'\n';
      else cout<<"No"<<'\n';
    }