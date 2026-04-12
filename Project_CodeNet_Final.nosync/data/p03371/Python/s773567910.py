A, B, C, X, Y = map(int, input().split())

INF = float('inf')
min_cost = INF

k = 0
while X - k >= 0 or Y - k >= 0:
    cost = A * max(0, X-k) + B * max(0, Y-k) + 2 * C * k
    min_cost = min(min_cost, cost)
    k += 1

print(min_cost)