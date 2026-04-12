from collections import Counter
n = int(input())
s = [input() for _ in range(n)]

ct = [27] * 26
ans = ''
for i in s:
    C = Counter(i)
    for j in range(26):
        k = C[chr(97 + j)]
        ct[j] = min(ct[j], k)

for i in range(26):
    ans += chr(97 + i) * ct[i]
print(ans)