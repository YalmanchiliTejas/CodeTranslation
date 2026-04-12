H,W = map(int, input().split())

lis = []
whitecol = [0]*W
for i in range(H):
    t = input()
    if '#' in t:
        lis.append(list(t))
        for j in range(len(t)):
            if t[j] == '#':
                whitecol[j] = 1
for i in lis:
    print(''.join([j for j,k in zip(i,whitecol) if k]))