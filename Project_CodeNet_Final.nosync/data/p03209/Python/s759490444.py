def f(n):
    return 2**(n+2)-3
def g(n):
    return 2**(n+1)-1
def p(x,n):
    if x==1:
        return 0
    if n==1:
        if 2<=x<=4:
            return x-1
        elif x>4:
            return 3
    if x==f(n-1)+2:
        return g(n-1)+1
    if x>=2*f(n-1)+2:
        return 2*g(n-1)+1
    if x<f(n-1)+2:
        return p(x-1,n-1)
    if x<2*f(n-1)+2:
        return g(n-1)+1+p(x-f(n-1)-2,n-1)
N,X = map(int,input().split())
print(p(X,N))