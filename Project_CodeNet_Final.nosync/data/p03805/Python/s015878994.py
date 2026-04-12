N, M = map(int, input().split())

matrix = [[0 for _ in range(N)] for _ in range(N)]

for _ in range(M):
    a, b = map(int, input().split())
    matrix[a - 1][b - 1] = 1
    matrix[b - 1][a - 1] = 1

def func(p, l):
    '''
    count = 0
    if Pから行ける場所が探索済み:
        if 全頂点探索済み:
            count = 1
        else:
            count = 0
    else:
        foreach Pから行ける未探索頂点:
            count += func(p, l)

    '''
    count = 0
    if all(l):
        count = 1
    else:
        for np, e in enumerate(matrix[p]):
            if e == 0:
                continue
            if p == np:
                continue
            if l[np] == True:
                continue

            l[np] = True
            count += func(np, l)
            l[np] = False

    return count

l = [False] * N
l[0] = True


print(func(0, l))