h, w = map(int, input().split())
A = [input() for i in range(h)]

def dfs(i, j):
    if(i == h-1 and j == w-1):
        return 'Possible'
    if(i < h-1 and A[i+1][j] == '#'):
        return dfs(i+1, j)
    if(j < w-1 and A[i][j+1] == '#'):
        return dfs(i, j+1)
    return 'Impossible'

if sum([a.count('#') for a in A]) != (h+w-1):
    print('Impossible')
else:
    print(dfs(0, 0))
