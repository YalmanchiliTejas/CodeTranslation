def ii():return int(input())
def iim():return map(int,input().split())
def iil():return list(map(int,input().split()))

h,w = iim()
l = []
for _ in range(h):
    l.append(list(input()))

flag = True
for i in range(h):
    for j in range(w):
        if l[i][j] == '#' and (i != h-1 or j != w-1):
            if i < h-1 and j < w-1:
                if l[i][j+1] == l[i+1][j]:
                    flag = False
            elif i == h-1:
                if l[i][j+1] != '#':
                    flag = False
            elif j == w-1:
                if l[i+1][j] != '#':
                    flag = False

for i in range(h):
    for j in range(w):
        if l[i][j] == '#' and i*j != 0:
            if i > 0 and j > 0:
                if l[i][j-1] == l[i-1][j]:
                    flag = False
            elif i == 0:
                if l[i][j-1] != '#':
                    flag = False
            elif j == 0:
                if l[i-1][j] != '#':
                    flag = False


print('Possible' if flag else 'Impossible')