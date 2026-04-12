N, *A = map(int, open(0).read().split())

ans = 0
S = 1
while S:
    S = sum(a // N for a in A)
    ans += S
    A = [a + S - (a // N) * (N + 1) for a in A]

print(ans)
