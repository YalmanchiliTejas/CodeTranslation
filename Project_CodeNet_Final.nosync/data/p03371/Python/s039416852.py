A, B, C, X, Y = map(int, raw_input().split())

cost = 0

if A + B >= 2 * C:
    cost += 2 * C * min(X, Y)
else:
    cost += (A + B) * min(X, Y)

diff = abs(X-Y)
if X > Y:
    if A > 2 * C:
        cost += 2 * C * diff
    else:
        cost += A * diff
else:
    if B > 2 * C:
        cost += 2 * C * diff
    else:
        cost += B * diff

print(cost)
