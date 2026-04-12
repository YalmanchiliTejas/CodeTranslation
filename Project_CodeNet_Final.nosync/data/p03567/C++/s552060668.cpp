#include<cstdio>
#include<cstring>
using namespace std;
char ch[6];
int main(){
scanf("%s", ch);
int N = strlen(ch);
for(int i = 0; i + 1 < N; ++i){
if(ch[i] == 'A' && ch[i + 1] == 'C'){
printf("Yes\n");
return 0;
}
}
printf("No\n");
return 0;
}