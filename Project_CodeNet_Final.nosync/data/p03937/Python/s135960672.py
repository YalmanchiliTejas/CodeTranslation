H,W=map(int,input().split())
a = [input() for _ in range(H)]
num = sum([row.count('#') for row in a])
if num==H+W-1:
    print('Possible')
else:
    print('Impossible')