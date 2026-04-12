n,x= list(map(int,input().split(" ")))
As = [1]
Ps = [1]
for i in range(n):
    As.append(As[i] * 2 + 3)
    Ps.append(Ps[i] * 2 + 1)

def rec(N,X):


    if X == 0:
        return 0
    if N == 0:
        return 1
    if X == 1:
        return 0
    if 1 < X <=As[N-1] + 1:
        return rec(N-1,X-1)

    if X == As[N-1] + 2:
        return Ps[N-1] + 1

    if As[N-1] + 2 < X < 2 * As[N-1] + 3:
        return Ps[N-1] + 1 + rec(N-1,X -As[N-1] -2)

    if X == 2*As[N-1] + 3:
        return 2 * Ps[N-1] + 1


ans = rec(n,x)
print(ans)