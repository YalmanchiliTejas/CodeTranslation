N = int(input())
A = list(map(int, input().split()))

ans = 0
while True:
    add = 0
    B = [0] * N
    cut = [0] * N
    for i, a in enumerate(A):
        d, m = divmod(a, N)
        B[i] = m
        cut[i] = d
        add += d

    for i, c in enumerate(cut):
        B[i] += add - c

    if not add:
        break

    ans += add
    A = B

print(ans)