H, W = map(int, input().split())
sp_cnt = 0
for _ in range(H):
    sp_cnt += input().count("#")
if sp_cnt == H+W - 1:
    print('Possible')
else:
    print('Impossible')
