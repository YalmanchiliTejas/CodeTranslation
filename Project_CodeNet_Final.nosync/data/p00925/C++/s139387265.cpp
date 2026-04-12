#include <cstdio>
 
int result;
char s[100];
 
int calc_ltor(char s[]){
    int res = s[0] - '0';
    for(int i=1;s[i]!='\0';i+=2){
        if(s[i] == '+'){
            res += s[i+1]-'0';
        }
        else if(s[i] == '*'){
            res *= s[i+1]-'0';
        }
    }
    return res;
}
int calc_mfirst(char s[]){
    int res = 0;
    int tmp = s[0] - '0';
    for(int i=1;s[i]!='\0';i+=2){
        if(s[i]=='+'){
            res += tmp;
            tmp = s[i+1] - '0';
        }else{
            tmp *= s[i+1] - '0';
        }
    }
    return res + tmp;
}
 
int main(){
    scanf("%s", s);
    scanf("%d", &result);
    int ltor = calc_ltor(s);
    int mfirst = calc_mfirst(s);
    //printf("%d %d\n", ltor, mfirst);
    if(ltor == result && mfirst == result){
        puts("U");
    }else if(ltor == result){
        puts("L");
    }else if(mfirst == result){
        puts("M");
    }else{
        puts("I");
    }
    return 0;
}