H,W = map(int,input().split())
road = [input()for i in range(H)]
rightest = 0
bottomest = 0
for i in range(H):
    for j in range(W):
        if road[i][j] == '#':
            if j < rightest:
                print('Impossible')
                exit()
            rightest = j
print('Possible')