A, B, C, X, Y = map(int, input().split())

kakaku = [[A, 'a'], [B, 'b'], [C, 'c']]
buff = [[X, 0], [Y, 1]]
huta = A+B

ab = C*2

if ab > huta:
    print(A*X+B*Y)
    exit()
else:
    buff.sort()
    # print(buff)
    ans = buff[0][0]*ab
    diff = buff[1][0]-buff[0][0]
    # print(kakaku)
    # print(buff)
    # print(buff[0][1])
    mn = kakaku[buff[1][1]][0]
    # print(mn)
    if mn > ab:
        print(ans+(diff*ab))
        # print('kotti')
        exit()
    else:
        print(ans+(diff*mn))
        exit()