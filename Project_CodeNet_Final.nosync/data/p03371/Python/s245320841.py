a, b, c, x, y = map(int, input().split())
if a+b <= c*2:
    print(a*x+b*y)
else:
    ans = 10**9
    for i in range(min(x,y)*2, 1+max(x,y)*2, 2):
        xx = x-i/2 if x-i/2 >= 0 else 0
        yy = y-i/2 if y-i/2 >= 0 else 0
        ans = min(ans, int(a*xx+b*yy+c*i))
    print(ans)