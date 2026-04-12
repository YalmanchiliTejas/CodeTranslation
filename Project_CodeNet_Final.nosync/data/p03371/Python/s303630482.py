a, b, c, x, y = map(int, input().split())

z = max(x,y) * 2
min_sum = c * z

for i in range(z):
    r = max(0, y - i) * b
    t = max(0, x - i) * a
    sum = c * i * 2 + r + t
    if sum < min_sum:
        min_sum = sum

print(min_sum)