#107
h, w = map(int, input().split())
h1 = [0]*h
w1 = [0]*w

a = [input() for _ in range(h)]

for i in range(h):
    for j in range(w):
        if(a[i][j]=='#'):
            h1[i] = 1
            w1[j] = 1

for i in range(h):
    if h1[i]==1:
        for j in range(w):
            if(w1[j]==1):
                print(a[i][j], end='')
        print()