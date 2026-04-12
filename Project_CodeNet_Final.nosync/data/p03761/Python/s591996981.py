n = int(input())
S = []
for i in range(n):
    S.append(input())

ans = ''

for alpha in range(ord('a'), ord('z')+1):
    Chr = chr(alpha)
    Count = []
    for i in range(n):
        Count.append(S[i].count(Chr))
    ans += Chr * min(Count)

print(ans)
