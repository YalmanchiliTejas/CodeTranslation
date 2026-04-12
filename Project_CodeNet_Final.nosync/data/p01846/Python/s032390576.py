#!/usr/bin/env python3
while True:
    s = input()
    if s == '#':
        break
    a, b, c, d = map(lambda x: int(x) - 1, input().split())
    tb = []
    for i, x in enumerate(s.split('/')):
        tb.append([])
        for ch in x:
            if ch == 'b':
                tb[i].append('b')
            else:
                tb[i] += list('.' * int(ch))
    tb[a][b] = '.'
    tb[c][d] = 'b'
    ans = []
    for i in range(len(tb)):
        tmp = ''
        cnt = 0
        for j in range(len(tb[i])):
            if tb[i][j] == 'b':
                if cnt > 0:
                    tmp += str(cnt)
                cnt = 0
                tmp += 'b'
            else:
                cnt += 1
        if cnt > 0:
            tmp += str(cnt)
        ans.append(tmp)
    print('/'.join(ans))

