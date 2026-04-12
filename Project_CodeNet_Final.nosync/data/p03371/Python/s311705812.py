a,b,c,x,y = map(int,input().split())
ans = x*a+y*b

if x < y:
    res = x*c*2+(y-x)*b
    ans = min(res,ans)
else:
    res = y*c*2+(x-y)*a
    ans = min(res,ans)
ans = min(ans,c*max(x,y)*2)
print(ans)