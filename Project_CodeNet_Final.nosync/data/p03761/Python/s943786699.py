n = int(input())
S = [list(input()) for _ in range(n)]
T = {}
for c in S[0]:
    T[c] = S[0].count(c)
for s in S:
    for t in T:
        if T[t] <= s.count(t):
            continue
        else:
            T[t] = s.count(t)

ans = sorted(T)
for a in ans:
    print(a*T[a], end='')
print()
