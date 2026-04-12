H, W = map(int, input().split())
tb = [list(input()) for _ in range(H)]

cnt = 0
for i in range(H):
    cnt += tb[i].count('#')

if cnt==H+W-1:
    print('Possible')
else:
    print('Impossible')