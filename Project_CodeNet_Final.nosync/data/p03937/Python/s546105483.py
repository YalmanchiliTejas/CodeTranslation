import sys
input = sys.stdin.readline

H,W = list(map(int,input().split()))
cnt = 0
for i in range(H):
    cnt += input().rstrip().count("#")
if cnt == H+W-1:
    print('Possible')
else:
    print('Impossible')
