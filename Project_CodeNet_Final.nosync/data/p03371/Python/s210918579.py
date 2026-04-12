a,b,c,x,y=map(int,input().split())
ans=9999999999999
for i in range(0,2*max(x,y)+1,2):
    ans=min(ans,c*i+a*(max(0,x-i//2))+b*(max(0,y-i//2)))
print(ans)