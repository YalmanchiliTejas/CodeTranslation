from collections import deque
import copy

N, M = map(int,input().split())
e_list = [[] for _ in range(N)]
for i in range(M):
    a, b = map(int,input().split())
    e_list[a - 1].append(b - 1)
    e_list[b - 1].append(a - 1)

waiting = deque()
flag_s = [0]*N
start_point = 0
waiting.append([start_point, flag_s])
cnt = 0
while len(waiting) != 0:
    cur_node, flag = waiting.pop()
    flag = copy.deepcopy(flag)
    flag[cur_node] = 1
    if sum(flag) == N: cnt += 1
    for e in e_list[cur_node]:
        if flag[e] != 1:
            waiting.append([e, flag])

print(cnt)