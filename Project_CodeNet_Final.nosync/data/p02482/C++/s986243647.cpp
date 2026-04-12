#include <iostream>
#include <cstdio>
using namespace std;
int x, y;
void print(char *f){
    printf("a %s b\n",f);
}
int main(){
    cin>>x>>y;
    if(x == y)print("==");
    else if(x < y)print("<");
    else print(">");
    return 0;
}