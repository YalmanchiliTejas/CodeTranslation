
L=[];
P=[];

def dfs(n,x):
    if(x==0):
        return 0;
    if(n==0):
        return 1;
    if(x==1):
        return 0;
    if(x>=L[n]-1):
        return P[n];
    nx=x-1;
    if(nx<=L[n-1]):
        return dfs(n-1,nx);
    if(nx==L[n-1]+1):
        return P[n-1]+1;
    if(nx>L[n-1]+1):
        return P[n-1]+1+dfs(n-1,nx-(L[n-1]+1));
    
def main():
    N,X = input().split();
    n=int(N);
    x=int(X);
    for i in range(0,51):
        L.append(0);
        P.append(0);
    L[0]=1;
    P[0]=1;
    for i in range(1,n+1):
        L[i]=L[i-1]*2+3;
        P[i]=P[i-1]*2+1;
    print(dfs(n,x));
    
main();
