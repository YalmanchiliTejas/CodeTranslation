h, w = map(int, input().split())
graph = [[0 for _ in range(w)] for _ in range(h)]
ans_graph = []
for i in range(h):
  w_g = input()
  for j in range(w):
    graph[i][j] = w_g[j]

pop_row_list = []
pop_ar_list = []
for i in range(h):
  flag = True
  for j in range(w):
    if graph[i][j] != '.':
      flag = False
  if flag == True:
    pop_row_list.append(i)

for j in range(w):
  flag = True
  for i in range(h):
    if graph[i][j] != '.':
      flag = False
  if flag == True:
    pop_ar_list.append(j)

ans_graph = []

for i in range(h):
  if i in pop_row_list:
    continue
  ans_graph.append([])
  for j in range(w):
    if j in pop_ar_list:
      continue
    ans_graph[-1].append(graph[i][j])

for i in range(len(ans_graph)):
  print("".join(ans_graph[i]))
