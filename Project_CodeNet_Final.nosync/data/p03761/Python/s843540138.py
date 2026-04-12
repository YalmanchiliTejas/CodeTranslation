

import sys
input = sys.stdin.readline
sys.setrecursionlimit(2147483647)
INF=float("inf")
MOD=10**9+7
# A = [ int(input()) for _ in range(N) ]
##############################

N = int(input())
S = []
for i in range(N):
    s = input().rstrip()
    S.append(sorted(s))

#print(S)

base = S.pop()
ans = []
for i in range(len(base)):
    expect = base[i]
    for j in S:
        if expect in j:
            continue
        else:
            expect = False
            break
    else:
        ans.append(expect)
        for j in range(len(S)):
            x = S[j].index(expect)
            S[j].pop(x)

print(''.join(ans))