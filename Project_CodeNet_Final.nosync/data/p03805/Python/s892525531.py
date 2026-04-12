N, M = map(int, input().split())

l = []

for i in range(M):
    l.append(list(map(lambda x: int(x) - 1, input().split())))

lis = [[] for i in range(N)]

for i in range(M):
    lis[l[i][0]].append(l[i][1])
    lis[l[i][1]].append(l[i][0])


# 隣接行列
# list = [[0 for c in range(M)] for r in range(N)]
#
# for i in range(M):
#     tmp_n, tmp_m = map(int, input().split())
#     list[tmp_n - 1][tmp_m - 1] = 1
#
#
# def dot(index1, index2):
#     results = [[0 for c in range(M)] for r in range(N)]
#     for (i, j) in zip(index1, zip(*index2)):
#         print(i,j)
#     return results



# 再起関数
# def travel(now, nextnodes, visited):
#     ends.append(visited)
#     visited.append(now + 1)
#     for node in nextnodes:
#         if node in visited:
#             continue
#         travel(node - 1, lis[node - 1], visited[:])
#
#
# travel(0, lis[0], [])

que = [[0, lis[0], []]]
ends = []

while que:
    now, nextnodes, visited = que.pop()
    ends.append(visited)
    visited.append(now)
    for node in nextnodes:
        if node in visited:
            continue
        que.append([node, lis[node], visited[:]])

print(len(list(filter(lambda ii: len(ii) is N, ends))))
