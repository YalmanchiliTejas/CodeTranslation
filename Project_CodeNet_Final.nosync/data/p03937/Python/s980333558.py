H, W = map(int, input().split())
A = [[s for s in input()] for _ in range(H)]

flag = True

prev = 0
for a in A:
    if prev > 0:
        if '#' in a[:prev]:
            flag *= False
    prev = max([n for n, v in enumerate(a) if v == '#'])
if flag:
    print('Possible')
else:
    print('Impossible')