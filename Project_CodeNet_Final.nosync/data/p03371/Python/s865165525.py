a,b,c,x,y = map(int,input().split())
ans = 0
if a+b>2*c:
    if x>y:
        ans = min(c*2*x,c*y*2+(x-y)*a)
    else:
        ans = min(c*2*y,c*x*2+(y-x)*b)
else:
    ans = a*x + b*y
print(ans)