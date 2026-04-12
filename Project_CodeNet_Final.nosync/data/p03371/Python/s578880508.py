a,b,c,x,y=map(int,input().split())
ans=float('inf')
for i in range(0,max(x,y)+1):
    s=i*2*c+max(x-i,0)*a+max(y-i,0)*b
    ans=min(s,ans)
print(ans)