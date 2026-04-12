h, w = map(int, input().split())
a = [list(list(input())) for _ in range(h)]

cnt = 0
rb = [x.count('.') == w for x in a]
for i in range(len(rb)):
    if rb[i] is True:
        del a[i-cnt]
        cnt += 1
cnt = 0
cb = [x.count('.') == len(a) for x in zip(*a)]
for i in range(len(cb)):
    if cb[i] is True:
        for j in range(len(a)):
            del a[j][i-cnt]
        cnt += 1

for x in a:
    print(*x, sep='')
