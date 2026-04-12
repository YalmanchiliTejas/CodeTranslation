# next_permutationで解く
import itertools
N, M = map(int, input().split())
graph = [[] for _ in range(N)]
for _ in range(M):
    a, b = map(lambda x: int(x)-1, input().split())
    graph[a].append(b)
    graph[b].append(a)

# 次の状態に遷移できるかどうかをしてbreakせず最後まで行けたらansをインクリメントする
ans = 0
for x in itertools.permutations(range(N)):
    now = 0
    if x[0] == 0:
        # 始点ノードが0のもののみ試す
        for e in x[1:]:
            if e not in graph[now]:
                break
            now = e
        else:
            ans += 1
print(ans)
