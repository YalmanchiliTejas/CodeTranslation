H, W = map(int,input().split())
road = 0
for i in range(H):
    A = list(input())
    road += A.count('#')
if road == H+W-1:
    print('Possible')
else:
    print('Impossible')

    