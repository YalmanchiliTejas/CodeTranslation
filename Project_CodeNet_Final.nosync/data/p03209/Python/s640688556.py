N, X = map(int,input().split())
def rec(n,x):
    f = 2**(n+1)-3
    if n==0:
        return 1
    if x==1:
        return 0
    elif x<=f+1:
        return rec(n-1,x-1)
    elif x==f+2:
        return 2**n
    elif x<=2*f+2:
        return 2**n+rec(n-1,x-(2**(n+1)-1))
    else:
        return 2**(n+1)-1
print(rec(N,X))
