H, W = map(int, input().split())
L = [list(input()) for i in range(H)]

c = 0
for i in L:
    c += i.count('#')
    
if c == H + W - 1:
    print('Possible')
else:
    print('Impossible')