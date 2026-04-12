import string

n = int(input())
S = []
for i in range(n):
    S.append(input())

ans = ''

for Chr in string.ascii_lowercase:
    Count = []
    for i in range(n):
        Count.append(S[i].count(Chr))
    ans += Chr * min(Count)

print(ans)