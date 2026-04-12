from itertools import permutations
n, m = map(int, input().split())

# 各edgeが結ばれているかどうかを二次元配列で保持(0:エッジなし, 1:エッジあり)
edges = [[0 for _ in range(n)] for _ in range(n)]
for i in range(m):
    a,b = map(int, input().split())
    edges[a-1][b-1] = 1
    edges[b-1][a-1] = 1

ans = 0
for l in permutations(range(1,n)):
    l = [0] + list(l)
    cnt = 1
    for i in range(n-1):
        # エッジを持たない場合はカウントしない
        if edges[l[i]][l[i+1]] == 0:
            cnt = 0
            break
    ans += cnt
print(ans)