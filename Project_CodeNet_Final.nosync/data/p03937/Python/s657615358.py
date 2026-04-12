from collections import deque
H,W = 0,0
A,cost = [],[]
INF = float('inf')

def dfs(x,y):
    global H,W,A,cost,INF
    q = deque([[x,y]])
    dx = [1,0]
    dy = [0,1]
    while len(q) != 0:
        tmp = q.pop()
        x,y = tmp[0],tmp[1]
        for i in range(2):
            if 0 <= x+dy[i] < H and 0 <= y+dx[i] < W:
                if A[x+dy[i]][y+dx[i]] == "#" and cost[x+dy[i]][y+dx[i]] == INF:
                    cost[x+dy[i]][y+dx[i]] = cost[x][y]+1
                    q.append([x+dy[i],y+dx[i]])
                    break


def main():
    global H,W,A,cost,INF
    H,W = map(int,input().split())
    A = [list(input()) for _ in range(H)]
    cost = [[INF]*W for _ in range(H)]
    cost[0][0] = 0
    dfs(0,0)
    ans = "Possible"
    flag = False
    for i in range(H):
        if flag:
            break
        for j in range(W):
            if A[i][j] == "#" and cost[i][j] == INF:
                ans = "Impossible"
                flag = True
                break
    print(ans)

if __name__ == '__main__':
    main()