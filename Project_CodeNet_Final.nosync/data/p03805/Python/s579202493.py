n, m = map(int, input().split())
a_and_b = [list(map(int, input().split())) for _ in range(m)]
point = [[] for _ in range(n)]
reached = [False for _ in range(n)]
answer = 0
for i in range(m):
    for j in range(n):
        if a_and_b[i][0] == j+1:
            point[j].append(a_and_b[i][1])
        if a_and_b[i][1] == j+1:
            point[j].append(a_and_b[i][0])


def dfs(start_point=0):
    global answer
    if not (False in reached):
        answer += 1
    for k in point[start_point]:
        if reached[k-1] is False:
            reached[k-1] = True
            dfs(start_point=k-1)
            reached[k-1] = False


reached[0] = True
dfs(start_point=0)
print(answer)