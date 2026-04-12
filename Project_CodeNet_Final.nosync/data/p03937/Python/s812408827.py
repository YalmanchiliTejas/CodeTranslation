H,W = map(int,input().split())

res = 0

for i in range(H):
    res += input().count('#')

if res == H+W-1:
    print('Possible')
else:
    print('Impossible')