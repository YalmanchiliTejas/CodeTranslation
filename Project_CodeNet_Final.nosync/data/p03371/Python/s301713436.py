a,b,c,x,y=map(int,input().split())
ans=10**9
for i in range(max(x,y)+1):
    ans=min(ans,i*2*c+max(0,x-i)*a+max(0,y-i)*b)
print(ans)