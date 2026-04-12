H, W = list(map(int, input().split()))

m = []
m.append('.'*(W+2))
for i in range(H):
    m.append('.'+input()+'.')

m.append('.'*(W+2))

x, y = 1, 1

while not(x==W and y==H):
    if(m[y][x+1]==m[y+1][x] or m[y][x-1]==m[y-1][x]=='#'):
        print('Impossible')
        exit()
    if(m[y][x+1]=='#'):
        x+=1
    elif(m[y+1][x]=='#'):
        y+=1


print('Impossible' if m[y-1][x]==m[y][x-1]=='#' else 'Possible')