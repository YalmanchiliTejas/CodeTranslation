a, b, c, x, y = map(int, input().split())
minVal = c * 2 * (10 ** 5)
for i in range(10**5):
    total = (c*2) * i + a * max(0, x-i) + b * max(0, y-i)
    minVal = min(total, minVal)
print(minVal)
