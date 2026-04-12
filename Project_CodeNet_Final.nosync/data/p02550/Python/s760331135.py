N, X, M = map(int, input().split())
A = X
P = set([A])
cnt, cnt2 = -1, -1
S = A
S2 = 0
off = -1
for i in range(N-1):
    A = A**2%M
    if A in P and cnt == -1:
        cnt = i
        off = A
    elif A ==off:
        cnt2 = i
        break
    S += A
    if cnt != -1:
        S2 += A
    P.add(A)
l = max(cnt2-cnt,1)
if cnt2==-1:
    res = S
else:
    res = 0
    for i in range((N-cnt-1)%l):
        res += off
        off = off**2%M
    res += S + ((N-cnt2-1)//l)*S2
print(res)
"""
9 4 7
"""
