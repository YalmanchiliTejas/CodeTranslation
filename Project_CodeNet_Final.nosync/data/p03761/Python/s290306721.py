import string
N = int(input())
L = [input() for _ in range(N)]
M = {}
for s in string.ascii_lowercase:
    M[s] = float('inf')
for s in string.ascii_lowercase:
    for l in L:
        M[s] = min(M[s],l.count(s))
ans = ''
for s in string.ascii_lowercase:
    ans += s*M[s]
print(ans)