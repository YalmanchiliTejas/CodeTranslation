a,b,c,x,y = map(int,input().split())
ans = 0
if a+b <= c*2:
    ans = a*x+b*y
else:
    if x>y:
        ans = min(2*c*y+(x-y)*a, 2*c*x)
    else:
        ans = min(2*c*x+(y-x)*b, 2*c*y)
print(ans)