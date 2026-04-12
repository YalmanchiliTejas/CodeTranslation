H, W = map(int, input().split())
a = []
b = []
for i in range(H):
        a.append(list(input()))

for i in range(H):
        all_white = True
        for j in range(W):
                if a[i][j] == '#':
                        all_white = False
        if all_white == False:
                b.append(a[i])
H = len(b)

for j in range(W):
        all_white = True
        for i in range(H):
                if b[i][j] == '#':
                        all_white = False
        if all_white == True:
                for i in range(H):
                        b[i][j] = ' '    

for i in range(H):
        for j in range(W):
                if b[i][j] != ' ':
                        print(b[i][j], end = '')
        print(end = '\n')