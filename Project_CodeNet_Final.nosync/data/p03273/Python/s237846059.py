h, w = map(int, input().split())
a = [list(input()) for _ in range(h)]

def rem(a):
    l = set([])
    c = set([])
    for i in range(len(a)):
        if ''.join(a[i]) == '.'*len(a[i]):
            l.add(i)
    for j in range(len(a[0])):
        col = ''.join([a[i][j] for i in range(len(a))])
        if col == '.'*len(a):
            c.add(j)
    if len(l) == 0 and len(c) == 0:
        return a
    else:
        a_new = []
        for i in range(len(a)):
            if i in l: continue
            line = []
            for j in range(len(a[0])):
                if j in c: continue
                line.append(a[i][j])
            a_new.append(line)
        return rem(a_new)
ans = rem(a)
for line in range(len(ans)):
    print(''.join(ans[line]))