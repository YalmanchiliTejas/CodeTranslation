H, W = map(int, input().split())
L = [list(input()) for _ in range(H)]

L1 = list(filter(lambda x: ''.join(x) != '.' * W, L))
L2 = list(filter(lambda x: x.count('.') != len(L1), list(zip(*L1))))
for t in list(zip(*L2)):
    print(''.join(t))
