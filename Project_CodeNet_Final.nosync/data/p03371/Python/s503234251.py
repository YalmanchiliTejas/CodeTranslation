a,b,c,x,y = list(map(int, input().split()))

c = 2*c

ans = a * x + b *y
for i in range(1, max(x, y)+1):
    _ans = c * i + a * max(x-i, 0) + b * max(y-i, 0)
    ans = min(ans, _ans)
print(ans)