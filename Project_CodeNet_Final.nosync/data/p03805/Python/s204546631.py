N, M = map(int, input().split())
adj_matrix = [[0]* N for _ in range(N)]

for i in range(M):
    a, b = map(int, input().split())
    adj_matrix[a-1][b-1] = 1
    adj_matrix[b-1][a-1] = 1

def dfs(v, used):
    #usedにFalseの値が入っていなかったら関数終了
    if not False in used:
        return 1
    
    ans = 0
    
    #adj_matrixがTrueじゃなかったら
    for i in range(N):
        #0だったら→枝がなかったら
        if not adj_matrix[v][i]:
            continue
        #usedに値があったら
        if used[i]:
            continue
        
        #used_iにTrueを代入
        used[i] = True
        #再帰
        ans += dfs(i, used)
        used[i] = False
    
    return ans
#main処理
#usedを全てFalseが詰まったリストにする
used = [False] * N
#used_0=1はTrue
used[0] = True

print(dfs(0, used))