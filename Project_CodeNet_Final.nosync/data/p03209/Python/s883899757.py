def dfs(l,x):
    if x == 0:
        return 0
    if l == 0:
        return 1
    if x == 1:
        return 0
    if x <= num[l] // 2:
        return dfs(l-1,x-1)
    if x == num[l]:
        x -= 1
    return patty[l-1] + 1 + dfs(l-1,x-num[l]//2-1)
n,x = map(int,input().split())
patty = [1]
num = [1]
for i in range(1,51):
    patty.append(patty[i-1]*2+1)
    num.append(num[i-1]*2+3)
print(dfs(n,x))