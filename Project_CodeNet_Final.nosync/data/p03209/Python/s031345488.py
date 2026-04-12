N, X = map(int, input().split())
ans = 0
while N >= 0:
    if N == 0:
        ans += 1
        break
    s = 2 ** (N + 2) - 3
    # V = 2 ** (N + 1) - 1
    if X == 1:
        # ans += 1
        break
    elif X < (s + 1) // 2:
        X -= 1
    elif X == (s + 1) // 2:
        ans += 2 ** N
        break
    elif X > (s + 1) // 2:
        ans += 2 ** N
        X -= (s + 1) // 2
    elif X == s:
        ans += 2 ** (N + 1) - 1
        break
    N -= 1
print(ans)
