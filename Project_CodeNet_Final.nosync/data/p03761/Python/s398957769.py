import string
n = int(input())
S = []
for _ in range(n):
    S.append(input())
alphabet = string.ascii_lowercase
summary = [{c: 0 for c in alphabet} for _ in range(n)]
for i, s in enumerate(S):
    for c in s:
        summary[i][c] += 1
ans = ''
for al in alphabet:
    ans += al * min(summary, key=lambda x: x[al])[al]
print(ans)