import itertools
n, m = map(int, input().split())
adj_matrix = [[0] * n for _ in range(n)]

for _ in range(m):
    a, b = map(int, input().split())
    adj_matrix[a-1][b-1] = 1
    adj_matrix[b-1][a-1] = 1

cnt = 0
for each in itertools.permutations(range(n)):
    if each[0] != 0:
        break
    flag = 1
    for i in range(n-1):
        flag *= adj_matrix[each[i]][each[i+1]]
    cnt += flag
print(cnt)