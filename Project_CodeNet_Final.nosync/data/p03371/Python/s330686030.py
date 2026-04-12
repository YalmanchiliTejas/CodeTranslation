a,b,c,x,y = map(int,input().split())
ans = 0
if a+b <= 2*c:
    ans = a*x+b*y
else:
    z = min(x,y)
    z1 = max(x,y)
    ans1 = 2*c*z1
    ans2 = 2*c*z + (z1-z) * (a if x>y else b)
    ans = min(ans1,ans2)
print(ans)