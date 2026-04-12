import numpy as np

H,W = map(int, input().split())
res = []
for i in range(H):
    res.append(list(map(list,input().split())))

initial_map = []
for i in res:
    row = [f for f in i]
    initial_map.append(row[0])

remove_list = []
for i in range(H):
    if '#' not in initial_map[i]:
        remove_list.append(i)

count = 0
for i in remove_list:
    initial_map.pop(i-count)
    count += 1

remove_list = []

initial_map_t = np.array(initial_map).T.tolist()

for i in range(W):
    if '#' not in initial_map_t[i]:
        remove_list.append(i)

count = 0
for i in remove_list:
    initial_map_t.pop(i-count)
    count += 1

res = np.array(initial_map_t).T.tolist()

for i in res:
    for j in i:
        print(j,end='')
    print()