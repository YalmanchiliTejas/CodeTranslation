n = int(input())
S = list(input())
for i in range(1, n):
    T = list(input())
    P = list(set(S) & set(T))
    N = len(P)
    for j in range(N):
        a =  min(S.count(P[j]), T.count(P[j]))
        P += [P[j] for l in range(a - 1)]
    S = P
S.sort()
ans = ''.join(S)
print(ans)