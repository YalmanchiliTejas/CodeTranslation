#include<iostream>
#include<string>

using namespace std;

string ope(int x, int y);

int main(void){
int a, b;

cin >>a >>b;
cout <<"a "<<ope(a, b)<<" b"<<endl;

return 0;
}

string ope(int x, int y){
string ans_ope;

if(x < y){
ans_ope = '<';
} else if(x > y){
ans_ope = '>';
} else{
ans_ope = "==";
}

return ans_ope;
}