#include<iostream> //cinなど
#include<string> //文字列
#include<algorithm> //sort など
#include<math.h> //paw(冪乗など)
#include<set> // 集合
#include<map> //写像
#include<stdio.h> //printf
#include<stack>

using namespace std;
int main(){
  string c;
  cin>>c;

  if(c=="a" ||c=="e"||c=="i"||c=="o"||c=="u"){
    cout<<"vowel"<<endl;
  }else{
    cout<<"consonant"<<endl;
  }
return 0;
}
