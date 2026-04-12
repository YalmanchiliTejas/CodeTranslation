N,X = map(int,input().split())

# 層の総数
T = [1]
for i in range(1, 50+1):
    T.append(T[i-1]*2+3)

def hash(n,x):
    return "{0:d},{1:d}".format(n,x)

# レベルnバーガーの下からx層内のパティの数
memo = dict()
def solve(n,x):
    global T, memo
    if hash(n,x) in memo:
        return memo[hash(n,x)]
    if n == 0 and x >= 1:
        memo[hash(n,x)] = 1
        return 1
    if x <= 1:
        memo[hash(n,x)] = 0
        return 0
    memo[hash(n,x)] = solve(n-1, min(x-1, T[n-1]))
    if x >= T[n-1]+2:
        memo[hash(n,x)] += 1
    if x >= T[n-1]+3:
        memo[hash(n,x)] += solve(n-1, min(x-1-T[n-1]-1, T[n-1]))
    return memo[hash(n,x)]

print(solve(N,X))
