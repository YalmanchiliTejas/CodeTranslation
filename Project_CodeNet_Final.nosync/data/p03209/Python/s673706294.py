N,X=map(int,input().split())
l=[2**(i+2)-3 for i in range(N+1)]#レベルLバーガー層数
p=[2**(i+1)-1 for i in range(N+1)]#レベルL パティ数
def f(n,x):
    if n==0:
        return 1
    elif x==1:
        return 0
    elif 1<x<=l[n-1]+1:
        return f(n-1,x-1)
    elif x==l[n-1]+2:
        return p[n-1]+1
    elif l[n-1]+2<x<l[n]:
        return p[n-1]+1+f(n-1,x-l[n-1]-2)
    elif x==l[n]:
        return p[n]
print(f(N,X))