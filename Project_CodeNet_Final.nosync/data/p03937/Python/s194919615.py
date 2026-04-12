H,W = map(int,input().split())
A = [input() for i in range(H)]

l = 1
x = 0
for i in range(H):
    while x<W-1 and A[i][x+1] == '#':
        x += 1
        l += 1
    if i+1<H and A[i+1][x] == '.':
        print('Impossible')
        exit()
    elif i+1<H:
        l += 1

c = sum(row.count('#') for row in A)
print('Possible' if c==l else 'Impossible')