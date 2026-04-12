n=int(input())
h=list(map(int,input().split()))
ans=1
if n==1:
    print(ans)
else:
    h0=h[0]
    for i in range(1,n):
        if h[i]>=h0:
            ans+=1
            h0=h[i]
    print(ans)