N = int(input())
S = [input() for k in range(N)]
A = "abcdefghijklmnopqrstuvwxyz"
C = [[0 for k in range(26)] for l in range(N)]

for k in range(N):
    for u in S[k]:
        C[k][A.find(u)] += 1

ans = ""
for p in range(26):
    t = 100
    for q in range(N):
        t = min(t,C[q][p])
    ans += A[p]*t
print(ans)