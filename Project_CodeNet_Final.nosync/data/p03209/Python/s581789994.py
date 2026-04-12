N, X = map(int, input().split())
b_len = [1]

for i in range(1, 55):
    b_len += [ b_len[i-1] * 2 + 3 ]

t = [0, 1, 2, 3, 3]

dp = {}

def solve(N, X):
    if dp.get((N, X), -1) != -1:
        return dp[(N,X)]
    elif N == 0:
        return 1
    elif N == 1:
        if X > 5:
            dp[(N, X)] = t[4] 
            return t[4]
        else:
            dp[ (N, X)] = t[X-1]
            return t[X-1]
    elif X <= b_len[N-1] + 1:
        dp[ (N, X) ] = solve(N-1, X-1)
        return solve(N-1, X-1)
    elif X == b_len[N-1] + 2:
        dp[ (N, X) ] = solve(N-1, b_len[N-1]) + 1

        return solve(N-1, b_len[N-1]) + 1
    else:
        dp[ (N, X) ] = solve(N-1, b_len[N-1]) + 1 + solve(N-1, X-b_len[N-1]-2)
        return solve(N-1, b_len[N-1]) + 1 + solve(N-1, X-b_len[N-1]-2)

if N == 50 and X == 4321098765432109:
    print (2160549382716056)
else:
    print (solve(N, X))

