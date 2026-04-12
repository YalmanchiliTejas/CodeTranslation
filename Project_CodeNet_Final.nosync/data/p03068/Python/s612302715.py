import sys

N = int(sys.stdin.readline().strip())
S = sys.stdin.readline().strip()
K = int(sys.stdin.readline().strip())

tmp = S[K-1]
ss = ""
for s in S:
    if s == tmp:
        ss += tmp
    else:
        ss += "*"

print(ss)
