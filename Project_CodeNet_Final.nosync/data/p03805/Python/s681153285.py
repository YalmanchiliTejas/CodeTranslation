import itertools

n, m = map(int, input().split())
my_set = set()

for i in range(m):
    a, b = map(int, input().split())
    my_set.add(a * 10 + b)
    my_set.add(b * 10 + a)

ret = 0
for item in itertools.permutations(range(1, n + 1)):
    is_ok = True
    if item[0] != 1:
        is_ok = False
    for i in range(len(item)-1):
        a, b = item[i], item[i+1]
        if a * 10 + b in my_set:
            continue
        else:
            is_ok = False
    if is_ok:
        ret += 1

print(ret)
