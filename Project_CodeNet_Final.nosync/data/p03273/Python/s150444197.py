H, W = [int(x) for x in input().split()]
A = [input() for _ in range(H)]
blank = [True] * W
for i in range(W):
    for j in range(H):
        if A[j][i] == '#':
            blank[i] = False
            break

for i in A:
    if '#' in i:
        for i,v in enumerate(i):
            if not blank[i]:
                print(v,end='')
        print()