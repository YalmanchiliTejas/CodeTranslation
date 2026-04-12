h, w = map(int, input().split())
a = [list(input()) for i in range(h)]

for i in range(h):
    for j in range(w):
        if a[i][j] == '#':
            a[i][j] = '.'
            break

for i in range(1,w):
    for j in range(h):
        if a[j][i] == '#':
            a[j][i] = '.'
            break

def check():
    for i in range(h):
        for j in range(w):
            if a[i][j] == '#':
                return 0;
    return 1;

if check():
    print ("Possible")
else :
    print ("Impossible")
