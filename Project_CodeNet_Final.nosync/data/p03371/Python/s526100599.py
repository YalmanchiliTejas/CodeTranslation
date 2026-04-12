a, b, c, x, y = map(int, input().split())
if x > y:
    x, y = y, x
    a, b = b, a
i = 0
total = a*(x-i) + (y-i)*b + 2*i*c
while True:
    # 1枚ずつ変えていく
    i += 1
    ntotal = a*max(0 ,x-i) + b*max(0, (y-i)) + 2*i*c
    if total < ntotal:
        break
    total = ntotal
print(total)