    #include<iostream>
    using namespace std;
    int main(){
      int a;
      cin>>a;
      char c[a];
      for(int i=0; i<a; i++)
      cin>>c[i];

      int b;
      cin>>b;
      char s=c[b-1];
      for(int i=0; i<a; i++){ 
       if(c[i]!=s){
          c[i]='*';
          cout<<c[i];}
        else
          cout<<c[i];
      }
      cout<<endl; 
    }
