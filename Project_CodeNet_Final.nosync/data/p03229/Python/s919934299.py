N=int(input())
a=list(sorted([int(input()) for _ in range(N)]))

if N%2==0:
    l1=a[:N//2]
    l2=a[N//2:N]
    ans=0
    for i in range(len(l1)):
        ans-=l1[i]*2
    ans+=l1[-1]
    for i in range(len(l2)):
        ans+=l2[i]*2
    ans-=l2[0]
else:
    l11=a[:N//2+1]
    l21=a[N//2+1:N]

    ans1=0
    for i in range(len(l11)):
        ans1-=l11[i]*2
    ans1+=l11[-1]+l11[-2]
    for i in range(len(l21)):
        ans1+=l21[i]*2

    l12=a[:N//2]
    l22=a[N//2:N]

    ans2=0
    for i in range(len(l12)):
        ans2-=l12[i]*2

    for i in range(len(l22)):
        ans2+=l22[i]*2
    ans2-=l22[0]+l22[1]
    ans=max(ans1,ans2)
print(ans)
