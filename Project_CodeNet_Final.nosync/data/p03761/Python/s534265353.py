
N = int(input())
S = [input() for _ in range(N)]
a2n = lambda c: ord(c) - ord('a')
n2a = lambda c: chr(c+97)

inf = 2 ** 30 - 1
idxs = [[0]*26 for _ in range(N)]
idx = [inf] * 26

for i in range(N):
    for s in S[i]:
        idxs[i][a2n(s)] += 1

for i in range(26):
    for j in range(N):
        idx[i] = min(idx[i],idxs[j][i])
        
ans = ''
for i in range(26):
    for j in range(idx[i]):
        ans += n2a(i)
print(ans)
        


