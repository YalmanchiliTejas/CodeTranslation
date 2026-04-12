ss = [[] for i in range(int(raw_input()))]

def ss_push(p, c):
    ss[int(p) - 1].append(c)

def ss_pop(p):
    return ss[int(p) - 1].pop()

while 1:
    vs = raw_input().split()
    if vs[0] == 'push':
        ss_push(vs[1], vs[2])
    elif vs[0] == 'pop':
        print ss_pop(vs[1])
    elif vs[0] == 'move':
        ss_push(vs[2], ss_pop(vs[1]))
    else:
        break