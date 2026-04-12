from sys import stdin
N = int(stdin.readline().rstrip())
S = stdin.readline().rstrip()
K = int(stdin.readline().rstrip())

chr = S[K-1]
ans = S
for c in range(0,N):
    if S[c] != chr:
        ans = ans.replace(S[c],'*')
print(ans)
