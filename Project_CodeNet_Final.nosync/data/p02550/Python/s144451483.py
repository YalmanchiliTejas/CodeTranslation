N, X, M = map(int, input().split())

known_set = set()
known_list = []
x_tmp = X

for _ in range(M):
    if x_tmp in known_set:
        break
    else:
        known_set.add(x_tmp)
        known_list.append(x_tmp)
        x_tmp = x_tmp**2%M


idx = known_list.index(x_tmp)
len_loops = len(known_set)-idx
r, s = divmod(N-idx ,len_loops)
idx = known_list.index(x_tmp)

res = sum(known_list[:idx]) + r * sum(known_list[idx:]) + sum(known_list[idx:idx+s])

print(res)