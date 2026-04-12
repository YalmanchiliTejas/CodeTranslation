import itertools
n, m = map(int, input().split())
d = [[0 for i in range(n)] for j in range(n)]
for i in range(m):
    a, b = map(int, input().split())
    a-=1
    b-=1
    d[a][b] = 1
    d[b][a] = 1
ans = 0

nums = [i for i in range(n)]
for num in itertools.permutations(nums):
    if(num[0] != 0):
        continue
    flag = True
    for i in range(n - 1):
        if(d[num[i]][num[i+1]] != 1):
            flag = False
            break
    if(flag):
        ans += 1

print(ans)
