a, b, c, x, y =map(int, input().split())
ab = 2*c
i = 0
cost = 0
minCost = 10**10
while i < 10**6:
    cost = i*ab
    cost += a *(max(0, (x-i)))
    cost += b *(max(0, (y-i)))
    if minCost >= cost:
        minCost = cost
    i += 1
print(minCost)