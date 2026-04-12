def resolve():
    n=int(input())
    a = list(map(int, input().split()))
    are=10**9+7
    s=sum(a)
    ans=0
    for i in range(n):
        s-=a[i]
        ans+=a[i]*s
        ans=ans%are
    print(ans)
resolve()