H, W = map(int, input().split())
cnt = 0
for i in range(H):
    A = input()
    cnt += A.count('#')
if (H + W - 1 == cnt): print('Possible')
else: print('Impossible')