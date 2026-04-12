n, m = [int(i) for i in input().split()]
A = [[] for i in range(n+1)]

for i in range(m):
    a, b = [int(i) for i in input().split()]
    A[a].append(b)
    A[b].append(a)

flag = [False] * (n+1)
flag[0] = True
cnt = 0

def dfs(i, flag):
    flag[i] = True
    for b in A[i]:
        if not flag[b]:
            dfs(b, flag[:])
    if all(flag) == True:
        global cnt
        cnt += 1

dfs(1, flag[:])
print(cnt)
