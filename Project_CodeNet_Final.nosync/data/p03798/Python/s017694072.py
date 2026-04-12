n = int(input())
s = input().rstrip()

cs = 'SW'
for ss in [[0, 0], [0, 1], [1, 0], [1, 1]]:
    for i in range(1, n + 1):
        if (ss[i % n] == 0 and s[i % n] == 'o') or (ss[i % n] == 1
                                                    and s[i % n] == 'x'):
            ss.append(ss[i - 1])
        else:
            ss.append(1 - ss[i - 1])
    if ss[-2] == ss[0] and ss[-1] == ss[1]:
        res = ''.join([cs[i] for i in ss[:-2]])
        print(res)
        break
else:
    print(-1)