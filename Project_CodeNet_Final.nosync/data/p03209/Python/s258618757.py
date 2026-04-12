N, X = map(int, input().split())

max_layer = 50
all_layer = [0]*(max_layer+1)
pate = [0]*(max_layer+1)
all_layer[0] = 1
pate[0] = 1

for i in range(1,max_layer+1):
    all_layer[i] = 2*all_layer[i-1] + 3
    pate[i] = 2*pate[i-1] + 1

def dfs(level, remain):
    ans = 0
    if level == 0:
        return 1

    if remain > 0:
        remain -= 1
    if remain > 0:
        if all_layer[level-1] <= remain:
            remain -= all_layer[level-1]
            ans += pate[level-1]
        else:
            ans += dfs(level-1, remain)
            return ans
    if remain > 0:
        remain -= 1
        ans += 1
    if remain > 0:
        if all_layer[level-1] <= remain:
            remain -= all_layer[level-1]
            ans += pate[level-1]
        else:
            ans += dfs(level-1, remain)
            return ans
    return ans
print(dfs(N, X))