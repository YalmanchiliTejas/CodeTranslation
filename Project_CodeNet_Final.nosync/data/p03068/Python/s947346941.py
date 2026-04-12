import sys


N = raw_input().strip()
S = raw_input().strip()
K = int(raw_input().strip())
A = []
ans = ''
for s in S:
    if s!=S[K-1]:
        A += '*'
    else:
        A += s
        
for x in A:
    ans += x
print(ans)