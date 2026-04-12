n,x,m=map(int,input().split())

mod=[0]*(m)

mod[x%m]=1
ans=x

for i in range(2,n+1):
    x=(x**2)%m
    #print(i,x)
    if mod[x]==0:
        ans+=x
        mod[x]=i
    else:
        #過去に2度来たことがある
        if mod[x]==-1:
            break
        #過去に1度来たことがある
        else:
            turn=i-mod[x]
            ans+=x*(((n-i)//turn+1))
            mod[x]=-1

print(ans)


    


