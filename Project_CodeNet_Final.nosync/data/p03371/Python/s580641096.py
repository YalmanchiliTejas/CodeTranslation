a,b,c,x,y = map(int, input().split())
c*=2
ans = min (a*x+b*y,c*max(x,y))
if x<y:
    ans = min(c*x+(y-x)*b,ans)
else:
    ans = min(c*y+(x-y)*a,ans)
print(ans)
