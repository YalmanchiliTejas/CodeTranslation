A, B, C, X, Y = map(int, input().split())

min_total = float("inf")
for i in range(max(X, Y) + 1):
    sum_C = 2 * C * i
    sum_A = A * max(0, X - i)
    sum_B = B * max(0, Y - i)
    total = sum_C + sum_A + sum_B
    if total < min_total:
        min_total = total

print(min_total)