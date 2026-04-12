n = int(input())
S = []
for _ in range(n):
    S.append(input())
alpha = [chr(ord('a') + i) for i in range(26)]
summary = [{c: 0 for c in alpha} for _ in range(n)]
for i, s in enumerate(S):
    for c in s:
        summary[i][c] += 1
ans = ''
for al in alpha:
    ans += al * min(summary, key=lambda x: x[al])[al]
print(ans)