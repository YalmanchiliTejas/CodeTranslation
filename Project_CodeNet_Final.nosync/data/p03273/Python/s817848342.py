H,W = map(int,input().split())
a = [input() for i in range(H)]
i = 0
while i<H:
    if not '#' in a[i]:
        del a[i]
        H -= 1
        i -= 1
    i += 1
a = list(map(list,zip(*a)))
i = 0
while i<W:
    if not '#' in a[i]:
        del a[i]
        W -= 1
        i -= 1
    i += 1
a = (list(map(list,zip(*a))))
for i in range(H):
    print(''.join(a[i]))
