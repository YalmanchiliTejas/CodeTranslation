N,X = map(int,input().split())

def dp(n,x):
    if x == 0:
        return 0
    if n == 0:
        return 1
    if x <= 2**(n+1)-2:
        return dp(n-1,x-1)
    else:
        return 2**n+dp(n-1,x-2**(n+1)+1)

print(dp(N,X))