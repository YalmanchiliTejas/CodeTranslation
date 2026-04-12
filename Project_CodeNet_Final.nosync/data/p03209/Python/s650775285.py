N,X = map(int,input().split())
ans=0
f=0
for i in range(N,1,-1):
    center = 2*pow(2,i)-1
    
    if X>center:
        X-=center
        ans+=pow(2,i)
    elif X==center:
        ans+=pow(2,i)
        f=1
        break
    elif X<center:
        X-=1

if f==0:
    ans+="BQQQB"[:X].count("Q")
print(ans)