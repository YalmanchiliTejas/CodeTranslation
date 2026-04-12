N, X = map(int, input().split())

L = [0]*(N+1)
L[0] = 1

for i in range(N):
    L[i+1] = L[i]*2 + 3
P = [0]*(N+1)
P[0] = 1
for i in range(N):
    P[i+1] = P[i]*2 + 1


def solve(n, x):
    #print(n, x)
    if x == L[n]:
        return(P[n])
    elif x <= n:
        return(0)
    else:
        ret = 0
        if x >= L[n-1] + 1:
            ret += P[n-1]
            x -= L[n-1] + 1
            if x > 0:
                ret += 1 + solve(n-1, x - 1)
        else:
            ret = solve(n-1, x-1)
        return(ret)


print(solve(N, X))
