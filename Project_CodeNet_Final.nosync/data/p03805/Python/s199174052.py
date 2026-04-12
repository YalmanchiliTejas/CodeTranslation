from collections import deque

n,m = map(int,input().split())

E = [[] for i in range(n+1)]

for i in range(m):
    a,b = map(int,input().split())
    E[a].append(b)
    E[b].append(a)

   
check = [0]*n
count = 0
def dfs(i):
    check[i-1] = 1
    result = 0
    if not 0 in check:
        
        return 1
        

    for j in E[i]:
        if check[j-1] == 0:
            check[j-1] = 1
            result += dfs(j)
            check[j-1]=0

    return result


print(dfs(1))
