N,X = map(int,input().split(" "))
num = [0] * (N+1)
p = [0] * (N+1)
num[0] = 1
p[0] = 1

for i in range(1,N+1):
    num[i] = num[i-1] * 2 + 3
    p[i] = p[i-1] * 2 + 1


def dfs(n,x):
    if n == 0:
        if x == 0: return 0
        else: return 1
        
    if x >= (num[n]-1):
        return p[n]

    if x >= (num[n-1]) + 2:
        return p[n-1] + 1 + dfs(n-1,x-((num[n-1]) + 2))

    if x == (num[n-1]) + 1:
        return p[n-1]

    if x >= 2:
        return dfs(n-1,x-1)

    return 0

print(dfs(N,X))


