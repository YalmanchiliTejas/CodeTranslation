H,W = map(int,input().split())
Data = []

for _ in range(H):
    Data.append(input())

hdata = set()
wdata = set()

for h in range(H):
    for w in range(W):
        if Data[h][w] == '#':
            hdata.add(h)
            wdata.add(w)

for h in range(H):
    output = False
    for w in range(W):
        if h in hdata and w in wdata:
            print(Data[h][w],end='')
            output = True
    if output:
        print('')
