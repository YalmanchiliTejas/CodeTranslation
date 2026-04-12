N, X = map(int, raw_input().split())

sz = [4 * 2 ** i - 3 for i in range(N + 1)]
num = [2 * 2 ** i - 1 for i in range(N + 1)]

def func(lv, id):
    mid = (sz[lv] + 1) / 2
    if lv == 0:
        return 1
    if id == 1:
        return 0
    if id == mid:
        return (num[lv] - 1) / 2 + 1
    if id == sz[lv]:
        return num[lv]
    if 1 < id < mid:
        return func(lv - 1, id - 1)
    if mid < id < sz[lv]:
        return func(lv - 1, id - sz[lv - 1] - 2) + num[lv - 1] + 1

print func(N, X)