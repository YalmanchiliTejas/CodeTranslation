N,X=map(int, input().split())

def func(n,k):
    if n==0:
        return 1
    a=2**(n+1)-1
    if k==a:
        return 2**n
    elif k==1:
        return 0
    elif k==2**(n+2)-3:
        return 2**(n+1)-1
    elif k<a:
        return func(n-1,k-1)
    else:
        return 2**n+func(n-1,k-(2**(n+1)-1))
print(func(N,X))
