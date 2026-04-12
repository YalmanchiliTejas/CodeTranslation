def dfs(now,parents):
    global ans
    global n
    for i in vert[now]:
        if i not in parents:
            dfs(i,parents+[now])
    if len(parents) == n:
        ans += 1
n,m = map(int,input().split())
vert = [[0] for i in range(n+1)]
for i in range(m):
    a,b = map(int,input().split())
    vert[a].append(b)
    vert[b].append(a)
parents = [0]
now = 1
ans = 0
dfs(1,parents)
print(ans)
# while parents:
#     if len(vert[now]) > 1:
#         next_place = vert[now].pop()
#         if vert[next_place][0] == 0:
#             now = next_place
#             vert[now][0] = 1

