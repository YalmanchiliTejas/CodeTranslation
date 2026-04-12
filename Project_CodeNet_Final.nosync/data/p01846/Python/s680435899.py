while 1:
    s = input()
    if s == '#':
        break
    M = []
    for l in s.split('/'):
        num = 0
        tmp = []
        for c in l:
            if c == 'b':
                if num > 0:
                    tmp.extend([0]*num)
                tmp.append(1)
                num = 0
            else:
                num = 10*num + int(c)
        if num > 0:
            tmp.extend([0]*num)
        M.append(tmp)
    a, b, c, d = map(int, input().split())
    assert M[a-1][b-1] == 1
    M[a-1][b-1] = 0
    assert M[c-1][d-1] == 0
    M[c-1][d-1] = 1
    ans = []
    for l in M:
        tmp = ""
        cnt = 0
        for c in l:
            if c:
                if cnt > 0:
                    tmp += str(cnt)
                cnt = 0
                tmp += 'b'
            else:
                cnt += 1
        if cnt > 0:
            tmp += str(cnt)
        ans.append(tmp)
    print("/".join(ans))