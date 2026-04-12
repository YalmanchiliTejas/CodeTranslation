a,b,c,x,y=map(int,input().split())
ans=float('inf')
for i in range(10**5+1):
    temp=i*2*c + max(0,x-i)*a +max(0,y-i)*b
    ans=min(ans,temp)
print(ans)