n,x,m=map(int,input().split())

lis=[0]*m

ans=x
ai=x
lis[ai]=[1,ans]
flg=0

for i in range(2,n+1):
    ai=(ai**2)%m
    if lis[ai]!=0:
        start=lis[ai][0]
        goal=i-1
        span=goal-start+1
        sumspan=ans-lis[ai][1]+ai
        flg=1
        break
    ans+=ai
    lis[ai]=[i,ans]

if flg:
    times=(n-goal)//span
    last=(n-goal)%span
    ans+=sumspan*times
    #print(last)
    #print(sumspan*times)
    if last==1:
        ans+=ai
    for i in range(0,last-1):
        ans+=ai
        #print(i)
        ai=(ai**2)%m
        if i == last-2:
            ans+=ai
    print(ans)
else:
    print(ans)