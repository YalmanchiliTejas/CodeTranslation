import copy

while 1:
    S = input()
    if S == '#':
        break
    a, b, c, d = map(lambda x : int(x)-1, input().split())
    F = list(S.split('/'))
    if a != c:
        f1 = list(F[a])
        f2 = list(F[c])
        F[a] = []
        for x in f1:
            if x == 'b':
                F[a].append('b')
            else:
                F[a] += [0]*int(x)
        F[c] = []
        for x in f2:
            if x == 'b':
                F[c].append('b')
            else:
                F[c] += [0]*int(x)
        F[a][b] = 0
        F[c][d] = 'b'
        l = 0
        y = ''
        for x in F[a]:
            if x == 'b':
                if l > 0:
                    y += str(l)
                    l = 0
                y += 'b'
            else:
                l += 1
        if l > 0:
            y += str(l)
        F[a] = y
        l = 0
        y = ''
        for x in F[c]:
            if x == 'b':
                if l > 0:
                    y += str(l)
                    l = 0
                y += 'b'
            else:
                l += 1
        if l > 0:
            y += str(l)
        F[c] = y
        print(*F, sep = '/')
    else:
        f1 = list(F[a])
        F[a] = []
        for x in f1:
            if x == 'b':
                F[a].append('b')
            else:
                F[a] += [0]*int(x)
        F[a][b] = 0
        F[c][d] = 'b'
        l = 0
        y = ''
        for x in F[a]:
            if x == 'b':
                if l > 0:
                    y += str(l)
                    l = 0
                y += 'b'
            else:
                l += 1
        if l > 0:
            y += str(l)
        F[a] = y
        print(*F, sep = '/')

