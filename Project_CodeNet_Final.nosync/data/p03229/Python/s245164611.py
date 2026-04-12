n=int(input())
a=[int(input()) for i in range(n)]

if n%2==0:
    a=sorted(a)
    if n==2:
        print(a[1]-a[0])
        exit()
    else:
        ans=0
        for i in range(n):
            if i<n//2-1:
                ans-=a[i]*2
            elif i==n//2-1:
                ans-=a[i]
            elif i==n//2:
                ans+=a[i]
            else:
                ans+=a[i]*2
        print(ans)
else:
    a=sorted(a,reverse=True)
    ans=0
    tmp=0
    for i in range(n):
        if i<n//2-1:
            tmp+=a[i]*2
        elif i==n//2-1 or i==n//2:
            tmp+=a[i]
        else:
            tmp-=a[i]*2
    ans=tmp
    tmp=0
    for i in range(n):
        if i<n//2:
            tmp+=a[i]*2
        elif i==n//2 or i==n//2+1:
            tmp-=a[i]
        else:
            tmp-=a[i]*2
    ans=max(ans,tmp)
    print(ans)
            