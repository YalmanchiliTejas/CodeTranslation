N, M = map(int, input().split(" "))
a = [0 for i in range(M)]
b = [0 for i in range(M)]
for i in range(M):
    a[i], b[i] = map(int, input().split(" "))

adj_matrix = [[0 for i in range(N)] for j in range(N)]
visited_flag = [0 for i in range(N)]
visited_flag[0] = 1

for i in range(M):
    adj_matrix[a[i]-1][b[i]-1] = 1
    adj_matrix[b[i]-1][a[i]-1] = 1

def find_next(idx, matrix, flag, nb_ans):
    if sum(flag) == N:
        return nb_ans+1
    for j in range(N):
        if matrix[idx][j] == 1 and flag[j] == 0:
            flag[j] = 1
            nb_ans = find_next(j, matrix, flag, nb_ans)
            flag[j] = 0

    return nb_ans

nb_ans = find_next(0, adj_matrix, visited_flag, 0)
print(nb_ans)