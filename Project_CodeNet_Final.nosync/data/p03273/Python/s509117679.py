h, w = map(int, input().split())
r = [list(input()) for i in range(h)]
for i in range(h):
    if not '#' in r[i]:
        r[i] = 'Nan'
r = [i for i in r if i != 'Nan']
l = list(map(list, zip(*r)))
for i in range(len(l)):
    if not '#' in l[i]:
        l[i] = 'Nan'
l = [i for i in l if i != 'Nan']
l = list(map(list, zip(*l)))
for i in range(len(l)):
    print(''.join(l[i]))
