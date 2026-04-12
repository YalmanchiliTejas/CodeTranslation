from collections import deque
H,W = map(int, input().split())
lst1 = [list(input()) for i in range(H) ] #迷路データ。２次元リストで格納し、"."と"#"(壁)からなる


def dfs(maze, visited, sh, sw):
    stack = deque([[sh, sw, 0]])
    visited[sh][sw] = 1
    while stack:
        h, w, t = stack.pop()
        if h == H-1 and w == W-1: #ゴールにたどりつけるなら
            return
        for j, k in ([1, 0], [-1, 0], [0, 1], [0, -1]): #4近傍について探索
            new_h, new_w = h+j, w+k
            if new_h < 0 or new_h >= H or \
               new_w < 0 or new_w >= W: #リスト外でないならelif条件へ
                continue
            elif maze[new_h][new_w] != "." and \
                visited[new_h][new_w] == 0: #行ったことがないかつ、壁でないなら
                visited[new_h][new_w] = 1
                stack.append([new_h, new_w, t+1])
    

visited = [[0]*W for _ in range(H)]
dfs(lst1, visited, 0, 0)

flag = 1
for i in range(H):
    for j in range(W):
        if not ((lst1[i][j] == "." and visited[i][j] == 0) \
        or (lst1[i][j] == "#" and visited[i][j] == 1)):
            flag = 0
            break
res = 0
for i in lst1:
    res += i.count("#")

if flag and res == H+W-1:
    print("Possible")
else:
    print("Impossible")
        
