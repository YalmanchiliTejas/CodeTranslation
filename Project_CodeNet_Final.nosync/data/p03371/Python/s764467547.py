A, B, C, X, Y = list(map(int, input().split()))
C *= 2

min_cost = float('inf')
for ab in range(max(X + 1, Y + 1)):
    cost = ab * C
    cost += A * max(0, X - ab)
    cost += B * max(0, Y - ab)
    if min_cost > cost:
        min_cost = cost
print(min_cost)
