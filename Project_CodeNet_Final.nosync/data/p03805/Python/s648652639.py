from itertools import permutations
N, M = list(map(int, input().split(' ')))
ADJ_MAT = [[0 for _ in range(N)] for _ in range(N)]
for _ in range(M):
    a, b = list(map(int, input().split(' ')))
    ADJ_MAT[a - 1][b - 1] = 1
    ADJ_MAT[b - 1][a - 1] = 1
answer = 0
for node_pattern in permutations(range(1, N)):
    # first node is fixed
    node_pattern = [0] + list(node_pattern)
    exists_path = True
    for i in range(N - 1):
        node_from = node_pattern[i]
        node_to = node_pattern[i + 1]
        if ADJ_MAT[node_from][node_to] == 0:
            exists_path = False
            break
    if exists_path:
        answer += 1
print(answer)