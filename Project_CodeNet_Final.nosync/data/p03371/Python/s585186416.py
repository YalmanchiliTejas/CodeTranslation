# 5
# ABC095 C Half and Half

a, b, c, x, y = map(int, input().split())

ans = a * x + b * y
for i in range(max(x,y)+1):
    _ans = 2 * i * c + a * max((x - i),0) + b * max((y - i),0)
    if _ans < ans:
        ans = _ans
        
print(ans)