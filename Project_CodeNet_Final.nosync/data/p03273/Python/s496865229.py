h,w = [int(i) for i in input().split(' ')]
a = [list(input()) for i in range(h)]

# 横除外
b = [i for i in a if not i.count('.') == w]
# 縦除外
h2 = len(b)
w2 = len(b[0])
ret = []
for i in range(w2):
    for x in range(h2):
        if b[x][i] == '#':
            ax = [b[xx][i] for xx in range(h2)]
            ret += [ax]
            break
    else:
        continue

for i in range(len(ret[0])):
    print(''.join([ret[x][i] for x in range(len(ret))]))
