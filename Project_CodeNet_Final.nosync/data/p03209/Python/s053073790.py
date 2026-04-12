N, X = list(map(int, input().split()))

a = [1]
p = [1]

for i in range(N):
    a.append(a[i] * 2 + 3)
    p.append(p[i] * 2 + 1)

def dp(N, X):
    if N == 0:
        return 1
    else:
        if X == 1:
            return 0
        elif X <= 1 + a[N-1]:
            return dp(N-1,X-1)
        elif X == 1 + a[N-1] + 1:
            return p[N-1] + 1
        elif X <= 1 + a[N-1] + 1 + a[N-1]:
            return p[N-1] + 1 + dp(N-1,X-1-a[N-1]-1)
        else:
            return p[N]

print(dp(N, X))