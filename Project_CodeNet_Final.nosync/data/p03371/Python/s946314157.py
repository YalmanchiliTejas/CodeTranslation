a,b,c,x,y=map(int,input().split())
ans=a*x+b*y
for ab in range(1,max(2*x,2*y)):
    if 2*ab*c+a*(max(x-ab,0))+b*(max(0,y-ab))<ans:
        ans=2*ab*c+a*(max(x-ab,0))+b*(max(0,y-ab))
print(ans)