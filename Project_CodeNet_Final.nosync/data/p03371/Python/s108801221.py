A, B, C, X, Y = map(int, input().split())
inf = float('inf')
amount = inf

for i in range(100001):
    amount = min(amount, 2*C*i + max(0, A*(X-i)) + max (0, B*(Y-i)))

print(amount)