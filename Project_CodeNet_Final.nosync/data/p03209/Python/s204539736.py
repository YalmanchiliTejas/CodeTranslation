p=lambda n:2**(n+1)-1
a=lambda n:2**(n+2)-3
def f(n,x):
    if n==0:
        return 0 if x<=0 else 1
    if x<=1+a(n-1):
        return f(n-1,x-1)
    return p(n-1)+1+f(n-1,x-2-a(n-1))
n,x=map(int,input().split())
print(f(n,x))
