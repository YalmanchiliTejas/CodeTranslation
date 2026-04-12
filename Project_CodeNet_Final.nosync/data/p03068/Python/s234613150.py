import sys


l = raw_input().split()
N = int(l[0])
l = raw_input().split()
S = l[0]
l = raw_input().split()
K = int(l[0])

c = S[K - 1]
ret = ''
for s in S:
    if s != c:
        ret += '*'
    else:
        ret += s
print(ret)
