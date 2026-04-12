N,M = map(int,input().split())

line = [[] for _ in range(N)]
for _ in range(M):
    a,b = map(int,input().split())
    line[a-1].append(b-1)
    line[b-1].append(a-1)

check = [False] * N

def dfs(now):
    global cnt
    global ans
    if cnt == N:
        ans += 1
    else:
        for i in line[now]:
            if check[i] == False:
                check[i] = True
                cnt += 1
                dfs(i)
                check[i] = False
                cnt -= 1

check[0] = True
cnt = 1
ans = 0
dfs(0)
print(ans)