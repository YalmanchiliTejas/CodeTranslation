from itertools import permutations

N, M = [int(i) for i in input().split()]
edge_dict = dict()
for i in range(M):
    _from, _to = [int(i) for i in input().split()]
    if edge_dict.get(_from) is None:
        edge_dict[_from] = list()
    if edge_dict.get(_to) is None:
        edge_dict[_to] = list()
    edge_dict[_from].append(_to)
    edge_dict[_to].append(_from)

cnt = 0
for combi in permutations(range(2,N+1)):
    flg = 0
    combi = [1] + list(combi)
    for i in range(N-1):
        candidate = edge_dict.get(combi[i])
        if candidate is None:
            flg = 1
            break
        if combi[i+1] not in candidate:
            flg = 1
            break
    if flg == 0:
        cnt += 1
print(cnt)