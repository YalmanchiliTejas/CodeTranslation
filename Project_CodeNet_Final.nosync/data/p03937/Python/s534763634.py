H, W = map(int, input().split())
a = [input() for i in range(H)]
c = 0
for s in a:
    c += s.count('#')
if c == H+W-1:
    print('Possible')
else:
    print('Impossible')