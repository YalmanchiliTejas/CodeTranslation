import itertools

n_m_input = list(map(int, input().split()))
n = n_m_input[0]
m = n_m_input[1]

all_point_string = ''.join([str(i+1) for i in range(n-1)])
path_string_list = list(itertools.permutations(all_point_string))

edge_list = [[0]*n for _ in range(n)]
counter = 0
answer = 0

for _ in range(m):
	edge = list(map(int, input().split()))
	edge_list[edge[0]-1][edge[1]-1] = 1
	edge_list[edge[1]-1][edge[0]-1] = 1

for path in path_string_list:
	counter = 0
	path_str = '0'+''.join(path)
	for i in range(n-1):
		if edge_list[int(path_str[i])][int(path_str[i+1])] == 1:
			counter += 1
	if counter == n-1:
		answer += 1

print(answer)
