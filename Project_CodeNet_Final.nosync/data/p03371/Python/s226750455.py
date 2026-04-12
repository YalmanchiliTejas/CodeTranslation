a,b,c,x,y=map(int,input().split())

ans=min(max(x,y)*2*c, a*x+b*y)
if x>y:
    ans=min(ans, y*2*c+a*(x-y))
else:
    ans=min(ans, x*2*c+b*(y-x))

print(ans)