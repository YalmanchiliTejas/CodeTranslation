a, b, c, x, y = [int(i) for i in input().split()]

ans = float("inf")
max_ab = max(x, y) * 2
# abピザをi(=2n)枚買うと想定
for i in range(0, max_ab+1, 2):
    rest_x = max(0, x - i//2)
    rest_y = max(0, y - i//2)
    cost = c*i + a*rest_x + b*rest_y
    ans = min(ans, cost)

print(ans)
