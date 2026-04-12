a,b,c,x,y = map(int,input().split())
ans = 10**19
ans = min(ans,a*x+b*y)
ans = min(ans,c*max(x,y)*2)
if x <= y:
    ans = min(ans,c*x*2+(y-x)*b)
else:
    ans = min(ans,c*y*2+(x-y)*a)
print(ans)