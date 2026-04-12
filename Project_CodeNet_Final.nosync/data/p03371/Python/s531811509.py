a, b, c, x, y = map(int, input().split())

ans = float('inf')
for k in range(2*max(x, y)+1):
    cost = c * k
    need_x = max(0, x - k // 2)
    need_y = max(0, y - k // 2)
    cost += a * need_x + b * need_y
    ans = min(ans, cost)
print(ans)