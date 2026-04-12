N,M=map(int,input().split(' '))
maze = [list(input()) for i in range(N)]
tmp = 0
for i in range(N):
    tmp += maze[i].count('#')
if tmp == N+M-1:
    print('Possible')
else:
    print('Impossible')