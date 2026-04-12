N, X, M = map(int, input().split())

visited = [False] * M

tmp = X
total_sum = X
visited[tmp] = True

total_len = 1
while True:
    tmp = (tmp ** 2) % M
    if visited[tmp]:
        loop_start_num = tmp
        break
    total_sum += tmp
    visited[tmp] = True
    total_len += 1

path_len = 0
tmp = X
path_sum = 0

while True:
    if tmp == loop_start_num:
        break
    path_len += 1
    path_sum += tmp
    tmp = (tmp ** 2) % M

loop_len = total_len - path_len
loop_sum = total_sum - path_sum


result = 0
if N <= path_len:
    tmp = X
    for i in range(N):
        result += X
        tmp = (tmp ** 2) % M
    print(result)
else:
    result = path_sum
    N -= path_len
    loops_count = N // loop_len
    loop_rem = N % loop_len
    result += loop_sum * loops_count
    tmp = loop_start_num
    for i in range(loop_rem):
        result += tmp
        tmp = (tmp ** 2) % M
    print(result)

# print("loop_start_num", loop_start_num)
# print("path_sum", path_sum)
# print("loop_sum", loop_sum)
