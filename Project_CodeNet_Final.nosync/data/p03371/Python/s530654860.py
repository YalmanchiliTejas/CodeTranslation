a, b, c, x, y = map(int, input().split())
mi = 10**10
for i in range(10**6):
    cost = c*2*i + a*max((x-i), 0) + b*max((y-i), 0)
    if cost < mi:
        mi = cost

print(mi)