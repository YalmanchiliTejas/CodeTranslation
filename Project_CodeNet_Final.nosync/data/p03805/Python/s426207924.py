#始点と終点は決まっていないので、軸優先や、深さ優先では手間が増えそう(これらは根っこのようなものがあるので)
#順列を使ってといて見ようと思う
#あ、、、始点決まってたわ()終点は決まってないですね。まあ、DFSやBFSでもできるけども。O(n^2)よりはO(n!)の方が小さい
from itertools import permutations

N,M = map(int,input().split())
E = []
for i in range(M):
    a,b = (int(_) for _ in input().split())
    E.append((a,b))
V = (i+1 for i in range(N))
one_strike_cnt = 0

for vertexs in permutations(V):
    #print(vertexs)
    if vertexs[0] != 1:
        continue
    #print(vertexs)
    one_strike = True#一筆描きできるならTrue
    for vertex_index in range(len(vertexs)-1):
        flag = False
        for i in range(M):
            a,b = E[i]
            if (a == vertexs[vertex_index] and b == vertexs[vertex_index+1]) or (a == vertexs[vertex_index+1] and b == vertexs[vertex_index]):
                flag = True
                break
        if not flag:
            one_strike = False
            break
    if one_strike:
        one_strike_cnt += 1

print(one_strike_cnt)
