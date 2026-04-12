n = int(input())
S = []
for i in range(n):
    S.append(input())

OrdA = ord('a')
ans = ''

for alpha in range(0, 26):
    Chr = chr(OrdA + alpha)
    Count = []
    for i in range(n):
        Count.append(S[i].count(Chr))
    ans += Chr * min(Count)

print(ans)
