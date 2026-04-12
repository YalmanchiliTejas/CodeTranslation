
def solve():
    n=int(input())
    a=[0]+list(map(int,input().split()))
    b=[0]*(n+1)
    for i in range(1,n+1) :
        b[i]=b[i-1]+a[i]
    m=int(1e9+7)
    ans=0
    for i in range(1,n+1) :
        ans= (ans+a[i]*b[i-1])%m
    return ans

print(solve())
