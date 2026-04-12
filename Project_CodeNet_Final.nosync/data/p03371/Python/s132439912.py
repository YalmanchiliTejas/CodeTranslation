A, B, C, X, Y = map(int, input().split())
ans = None
for ab_count in range(0, max(X, Y) * 2 + 1, 2):
    a_count = max(0, X - ab_count // 2)
    b_count = max(0, Y - ab_count // 2)
    amount = a_count * A + b_count * B + ab_count * C
    if ans is None:
        ans = amount
    else:
        ans = min(ans, amount)
print(ans)