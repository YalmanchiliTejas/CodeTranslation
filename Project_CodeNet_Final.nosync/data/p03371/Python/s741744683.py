a, b, c, x, y = map(int, input().split())
min_sum = pow(10, 10)

for i in range(0, max(x, y) * 2 + 1, 2):
    d = x - i // 2
    e = y - i // 2
    if d < 0 :
        d = 0
    if e < 0:
        e = 0
    sum = a * d + b * e + c * i
    
    if min_sum > sum :
        min_sum = sum

print(min_sum)