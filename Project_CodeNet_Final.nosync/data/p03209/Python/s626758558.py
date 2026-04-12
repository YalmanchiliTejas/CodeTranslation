n, x = [int(i) for i in input().split()]

memo = dict()
size = [0] * (n+1)
size[0] = 1

for i in range(1, n+1):
    size[i] = size[i-1] * 2 + 3

def dfs(i):
    global x
    res = 0
    if x <= 0:
        return 0
    if size[i] <= x and i in memo:
        x -= size[i]
        return memo[i]
    if i == 0:
        x -= 1
        return 1
    x -= 1 #B
    res += dfs(i-1)
    x -= 1 #P
    if x < 0:
        return res
    res += 1 #P
    res += dfs(i-1)
    x -= 1 #B
    memo[i] = res
    return res


print(dfs(n))