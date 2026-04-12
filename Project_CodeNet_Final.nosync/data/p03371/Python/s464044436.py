a,b,c,x,y=map(int,input().split())
ans=float('inf')
for i in range(10**5+1):
    tmp=2*i*c+a*max(x-i,0)+b*max(y-i,0)
    ans=min(tmp,ans)
print(ans)