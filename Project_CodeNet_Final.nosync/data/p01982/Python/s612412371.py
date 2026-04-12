while 1:
    n,l,r=map(int,input().split())
    if n==l==r==0:break
    a=[]
    for i in range(n):
        a.append(int(input()))
    ans=0
    a.append(1)
    for i in range(l,r+1):
        for j in range(n+1):
            if i%a[j]==0:
                if j%2==0:ans+=1
                break
    print(ans)
