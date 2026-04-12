# coding: utf-8

a,b,c,x,y = map(int,input().split())

ans = min(a*x+b*y, a*x+c*2*y, b*y+c*2*x)

if x <= y:
    u = c*x*2+b*(y-x)
else:
    u = c*y*2+a*(x-y)
v = c*2*(max(x,y))
ans = min(ans,u,v)
print(ans)