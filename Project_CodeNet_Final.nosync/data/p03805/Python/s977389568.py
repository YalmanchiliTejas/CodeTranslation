import itertools

n, m = map(int, input().split())
li = [list(map(int, input().split())) for i in range(m)]
iter_list = itertools.permutations(range(1, n + 1), n)


def checker(tup):
    if tup[0] != 1:
        return False
    for i in range(len(tup)-1):
        path = [tup[i], tup[i + 1]]
        re_path = [tup[i+1], tup[i]]
        if not (path in li or re_path in li):
            return False
    return True


res = 0
for i in iter_list:
    if checker(i):
        res += 1

print(res)
