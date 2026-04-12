n, m = map(int, input().split())
mat = [input() for _ in range(n)]
i = 0
j = 0

while i != n-1 or j != m-1:
    down = '.'
    right = '.'
    downleft = '.'
    rightup = '.'
    if i != n-1:
        down = mat[i+1][j]
        if j != 0:
            downleft = mat[i+1][j-1]
    if j != m-1:
        right = mat[i][j+1]
        if i != 0:
            rightup = mat[i-1][j+1]
    
    if down == right:
        print('Impossible')
        exit()
    elif down == '#': 
        if downleft == down:
            print('Impossible')
            exit()
        i+=1
    else: 
        if rightup == right:
            print('Impossible')
            exit()
        j+=1

print('Possible')