a,b,c,x,y = map(int,input().split())
ans = 2000000000
if x >= y:
    cnt = 0
    cnt += y * 2 * c
    cnt += (x - y) * a
    ans = min(ans,cnt)
else:
    cnt = 0
    cnt += x * 2 * c
    cnt += (y - x) * b
    ans = min(ans,cnt)
ans = min(ans, a * x + b * y)
ans = min(ans, max(x,y) * 2 * c)
print(ans)