#include <bits/stdc++.h>

int main() {
    FILE * fi, * fout;
    int a,b,c;
    //fi = fopen("A.in" ,"r");
    //fout = fopen("A.out" ,"w");
    fi=stdin;
    fout=stdout;
    fscanf(fi,"%d%d%d" ,&a,&b,&c);
    if((a*100+b*10+c)%4==0)
      fprintf(fout,"YES\n");
    else
      fprintf(fout,"NO\n");
    //fclose(fi);
    //fclose(fout);
}
