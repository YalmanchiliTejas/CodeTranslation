from collections import Counter
from sys import exit, stdin
N = int(stdin.readline().rstrip())
if N == 1:
    print(''.join(sorted(stdin.readline().rstrip())))
    exit()
S = [Counter(stdin.readline().rstrip()) for _ in range(N)]
inter_chars = {}
for i in range(0, N-1):
    inter_chars = S[i].keys() & S[i+1].keys()
ans = {}
for i in range(N):
    for c in inter_chars:
        if c not in ans:
            ans[c] = S[i][c]
        elif S[i][c] < ans[c]:
            ans[c] = S[i][c]
print(''.join(sorted(k*v for k, v in ans.items())))