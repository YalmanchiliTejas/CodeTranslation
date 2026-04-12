n=int(input())
a=list(map(int,input().split()))
if n%2==0:
    b=[a[n-1-2*i] for i in range(0,n//2)]
    c=[a[2*i] for i in range(0,n//2)]
    ans=b+c
    print(*ans)
else:
    b=[a[n-1-2*i] for i in range(0,(n-1)//2+1)]
    c=[a[2*i+1] for i in range(0,(n-1)//2)]
    ans=b+c
    print(*ans)
