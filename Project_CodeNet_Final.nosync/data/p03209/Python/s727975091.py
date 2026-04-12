p = lambda n:2**(n+1)-1
a = lambda n:2**(n+2)-3


def dfs(n,x):
    if n==0:
        return 0 if x<=0 else 1
    if x<=1+a(n-1):
        return dfs(n-1,x-1)
    else:
        return p(n-1)+1 + dfs(n-1,x-2-a(n-1))

n, x = map(int, input().split())
print(dfs(n,x))
