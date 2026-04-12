A, B, C, X, Y = map(int, input().split())
ret = float('inf')
for i in range(10 ** 5 + 1):
    ret = min(ret, A * max(0, X - i) + B * max(0, Y - i) + 2 * i * C)
print(ret)