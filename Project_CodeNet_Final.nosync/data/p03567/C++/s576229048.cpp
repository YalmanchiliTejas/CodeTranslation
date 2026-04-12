#include<bits/stdc++.h>
using namespace std;
char a[10];
int c,d;
int main(){
    scanf("%s",a);
    if(a[0]=='A'&&a[1]=='C') {puts("Yes");return 0;}
    if(a[1]=='A'&&a[2]=='C') {puts("Yes");return 0;}
    if(a[2]=='A'&&a[3]=='C') {puts("Yes");return 0;}
    if(a[3]=='A'&&a[4]=='C') {puts("Yes");return 0;}
    puts("No");
}