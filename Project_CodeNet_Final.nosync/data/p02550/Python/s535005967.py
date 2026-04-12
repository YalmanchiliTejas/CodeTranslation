n,x,mod=map(int,input().split())
d=[-1]*mod
ans=0
syu=0
al=[]
for i in range(n):
    if d[x]!=-1:
        en=i
        syu=i-d[x]    
        break
    ans+=x
    al.append(x)
    d[x]=i
    x=x*x%mod   
if syu==0:
    print(ans)
    exit()
ans+=((n-en)//syu)*sum(al[d[x]:en])
for i in range((n-en)%syu):
    ans+=x%mod
    x=x*x%mod
print(ans)