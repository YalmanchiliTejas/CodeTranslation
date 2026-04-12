#include <cstdio>
#include <cstring>
const int nmax=100023;
char ch[nmax];
int n;
int sol[nmax];
int left(int pos)
{
    if(pos==0) return n-1;
    return pos-1;
}
int right(int pos)
{
    if(pos==n-1) return 0;
    return pos+1;
}
int check(int pos)
{
    int ct=0;
    while(1)
    {
        if(sol[left(pos)]!=0&&sol[right(pos)]!=0) ++ct;
        if(ct==n+2) break;
        if(sol[pos]==1)
        {
            if(ch[pos]=='o')
            {
                if(sol[left(pos)]!=sol[right(pos)]&&sol[right(pos)]!=0&&sol[left(pos)]!=0) return 0;
                sol[right(pos)]=sol[left(pos)];
            }
            else if(ch[pos]=='x')
            {
                if(sol[left(pos)]==sol[right(pos)]) return 0;
                sol[right(pos)]=3-sol[left(pos)];
            }
        }
        else
        {
            if(ch[pos]=='x')
            {
                if(sol[left(pos)]!=sol[right(pos)]&&sol[right(pos)]!=0&&sol[left(pos)]!=0) return 0;
                sol[right(pos)]=sol[left(pos)];
            }
            else
            {
                if(sol[left(pos)]==sol[right(pos)]) return 0;
                sol[right(pos)]=3-sol[left(pos)];
            }
        }
        pos=right(pos);
    }
    return 1;
}
void reset()
{
    for(int i=0;i<n;i++) sol[i]=0;
}
int main()
{
   // freopen ("in.in","r",stdin);
    scanf("%d",&n);
    scanf("%s",ch);
    int pos=-1;
    for(int i=0;i<n;i++)
    {
        if(ch[i]=='o')
        {
            pos=i;
            break;
        }
    }
    if(pos==-1)
    {
        printf("-1\n");
        return 0;
    }
    sol[pos]=1,sol[left(pos)]=1,sol[right(pos)]=1;
    if(check(right(pos)))
    {
        for(int i=0;i<n;i++)
        {
            if(sol[i]==1) printf("S");
            else printf("W");
        }
        return 0;
    }
    reset();
    sol[pos]=1,sol[left(pos)]=2,sol[right(pos)]=2;
    if(check(right(pos)))
    {
        for(int i=0;i<n;i++)
        {
            if(sol[i]==1) printf("S");
            else printf("W");
        }
        return 0;
    }
    reset();
    sol[pos]=2;
    sol[left(pos)]=1,sol[right(pos)]=2;
    if(check(right(pos)))
    {
        for(int i=0;i<n;i++)
        {
            if(sol[i]==1) printf("S");
            else printf("W");
        }
        return 0;
    }
    reset();
    sol[pos]=2;
    sol[left(pos)]=2,sol[right(pos)]=1;
    if(check(right(pos)))
    {
        for(int i=0;i<n;i++)
        {
            if(sol[i]==1) printf("S");
            else printf("W");
        }
        return 0;
    }
    printf("-1\n");
}
