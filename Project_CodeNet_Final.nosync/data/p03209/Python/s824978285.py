n, x = map(int, input().split())
layer = [1]
patty = [1]
for _ in range(n):
    layer.append(1 + layer[-1] + 1 + layer[-1] + 1)
    patty.append(patty[-1] + 1 + patty[-1])
res = 0
while x > 0:
    x -= 1
    if x >= layer[n-1] + 1:
        res += 1
    while x >= layer[n-1]:
        res += patty[n-1]
        x -= layer[n-1] + 1
    n -= 1
print(res)