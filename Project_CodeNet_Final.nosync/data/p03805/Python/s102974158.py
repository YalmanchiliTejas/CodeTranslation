import itertools
n, m = map(int, input().split())
ab_list = [tuple(map(int, input().split())) for _ in range(m)]

path_list = sorted(iter for iter in itertools.permutations(range(2, n+1), n-1))

counter = 0

for path_i in path_list:
  path = (1, )+path_i
  
  result_list = [True for s_e in zip(path, path[1:]) if tuple(sorted(s_e)) in ab_list]
  
  if sum(result_list) == len(path)-1: counter += 1
    
print(counter)