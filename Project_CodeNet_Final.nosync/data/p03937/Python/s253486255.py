H,W = map(int,input().split())
res = ''
for i in range(H):
    res += input()
if res.count('#') == H+W-1:
    print('Possible')
else:
    print('Impossible')
