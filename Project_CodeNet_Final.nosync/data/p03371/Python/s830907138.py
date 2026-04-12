a,b,c,x,y=map(int,input().split())
ans=float('inf')
for i in range(10**5+1):
    tmp=i*c*2+a*max(x-i,0)+b*max(y-i,0)
    ans=min(ans,tmp)
print(ans)
