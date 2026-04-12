import string

INF = float('inf')

n = int(input())
ss = [input() for _ in range(n)]

ans_d = {c: INF for c in string.ascii_lowercase}  # AtoZ
for s in ss:
    d = {c: 0 for c in string.ascii_lowercase}  # AtoZ
    for c in s:
        d[c] += 1
    for c in string.ascii_lowercase:
        ans_d[c] = min(ans_d[c], d[c])

ans = ''
for c in string.ascii_lowercase:
    ans += c * ans_d[c]
print(ans)