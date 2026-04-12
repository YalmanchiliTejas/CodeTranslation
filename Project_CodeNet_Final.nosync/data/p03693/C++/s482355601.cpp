    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
     
    int main()
    {
    int r,g,b;
     scanf("%d %d %d",&r,&g,&b);
     int a=(10*g)+b;
     if(a%4==0)
      printf("YES\n");
     else printf("NO\n");
     return 0;
    }