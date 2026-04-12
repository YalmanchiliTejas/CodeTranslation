from sys import exit, stdin
H, W = [int(_) for _ in stdin.readline().rstrip().split()]
S = [list(stdin.readline().rstrip()) for _ in range(H)]
cnt = 0
for l in S:
    cnt += l.count('#')
if cnt == H + W - 1:
    print('Possible')
else:
    print('Impossible')