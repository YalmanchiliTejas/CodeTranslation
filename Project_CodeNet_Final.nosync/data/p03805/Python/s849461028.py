import copy
n, m = [ int(v) for v in input().split() ]
connect_matrix = [[ 0 for i in range(n)] for j in range(n)]

for i in range(m):
    a, b = [ int(v)-1 for v in input().split() ]
    connect_matrix[a][b] += 1
    connect_matrix[b][a] += 1


one_path_list = [[0]]
for i in range(n-1):
    next_path_list = []

    for j in range(len(one_path_list)):

        next_point_list = [ k for k in range(n) if connect_matrix[one_path_list[j][-1]][k] == 1 and k not in one_path_list[j]]

        for k in range(len(next_point_list)):
            next_path_list.append(copy.deepcopy(one_path_list[j])+[next_point_list[k]])

    one_path_list = next_path_list 

print(len(one_path_list))