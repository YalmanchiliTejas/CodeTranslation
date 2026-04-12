#include<cstdio>

int main(){
    int A, B, C, X, Y;
    int AnsAllCmax, AnsAllCmin, AnsAB, Ans;
    scanf("%d%d%d%d%d", &A, &B, &C, &X, &Y);
    if(X >= Y){
        AnsAllCmax = X * C * 2;
        AnsAllCmin = Y * C * 2+ A * (X - Y);
    }else{
        AnsAllCmax = Y * C * 2;
        AnsAllCmin = X * C * 2 + B * (Y - X);
    }
    AnsAB = A * X + B * Y;
    Ans = AnsAB;
    if(AnsAllCmax < Ans) Ans = AnsAllCmax;
    if(AnsAllCmin < Ans) Ans = AnsAllCmin;
    printf("%d", Ans);
    return 0;
}