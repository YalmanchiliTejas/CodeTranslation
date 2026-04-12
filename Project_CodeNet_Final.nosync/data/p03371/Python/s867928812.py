a, b, c, x, y = map(int, input().split())

tmp1 = c * min(x, y) * 2
tmp2 = 0
if x < y:
    tmp2 = b * abs(x - y)

elif x > y:
    tmp2 = a * abs(x - y)

else:
    tmp2 = float("INF")

pattern1 = (a * x + b * y)
pattern2 = tmp1 + tmp2
pattern3 = c * max(x, y) * 2

print(min(pattern1, pattern2, pattern3))
