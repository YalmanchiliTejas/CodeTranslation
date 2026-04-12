import itertools
N,M = (int(i) for i in input().split())
K = []
for i in range(M):
    J = [int(i) for i in input().split()]
    J.sort()
    K.append(J)

#1以外の頂点リストを作成
vertex = []
for i in range(N-1):
    vertex.append(i+2)
#順列作成
X = list(itertools.permutations(vertex))

#各値ごとに有無をチェック
ans = 0
for i in X:
    start = 1
    localcount = 0
    for j in i:
        tmp = [start,j]
        tmp.sort()
        if tmp in K:            
            localcount += 1   
        start = j
            
    if localcount == N-1:
        ans += 1

print(ans) 