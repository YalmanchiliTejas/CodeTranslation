#095_C
a,b,c,x,y=map(int,input().split())
ans=10**10

for ab in range(0,max(x,y)+1):
    tmp=max(0,x-ab)*a+max(0,y-ab)*b+ab*2*c
    ans=min(ans,tmp)

print(ans)