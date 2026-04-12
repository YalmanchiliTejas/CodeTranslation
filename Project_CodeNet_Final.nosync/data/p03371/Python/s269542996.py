a,b,c,x,y = map(int,input().split())
ans = 0
if 2*c >= a+b:
    print(a*x+b*y)
else:
    while x >= 1 and y >= 1:
        ans += 2*c
        x -= 1
        y -= 1
    print(min(ans + a*x+b*y,ans + 2*c*(x+y)))
