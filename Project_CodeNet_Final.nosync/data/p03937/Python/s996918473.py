h, w = map(int, input().split())
A = []
res_w = []
for i in range(h):
    line = [s for s in input()]
    c = []
    for j in range(len(line)):
        if line[j] == '#':
            c.append(j)
            if (len(c) > 1) and (c[-2] - c[-1] > 1):
                print('Impossible')
                exit()
            if j not in res_w:
                res_w.append(j)
            else:
                if max(res_w) > j:
                    
                    print('Impossible')
                    exit()
print('Possible')


