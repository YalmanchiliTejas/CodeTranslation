def f(n):
    if n==0:
        return 1
    return 2*f(n-1)+3
def g(n):
    if n==0:
        return 1
    return 2*g(n-1)+1
def F(n,x):
    if n==0:return 1
    if x<=n:return 0
    if x<=f(n-1)+1:
        return F(n-1,x-1)
    elif x==f(n-1)+2:
        return g(n-1)+1
    else:
        return g(n-1)+1+F(n-1,x-f(n-1)-2)
N,X = map(int,input().split())
print(F(N,X))