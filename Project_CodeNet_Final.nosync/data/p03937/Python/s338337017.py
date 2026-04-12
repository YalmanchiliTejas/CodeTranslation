h, w =list(map(int, input().split())) 
mat = []
for i in range(h):
    s = input()
    mat.append([s[x] for x in range(w)])

flag = True
for i in range(h-1):
    for j in range(w-1):
        if mat[i][j] == '#':
            if( (mat[i+1][j]=='#')& (mat[i][j+1]=='#') ):
                flag = False

for i in range(1,h):
    for j in range(1,w):
        if mat[i][j] == '#':
            if( (mat[i-1][j]=='.')& (mat[i][j-1]=='.') ):
                flag = False

if flag :
    print('Possible')
else:
    print('Impossible')