H,W = map(int,input().split())
mat = []
for i in range(H):
    a = list(input())
    if '#' in a:
        mat.append(a)
answ = []
for i in range(W):
    flag = False
    for j in range(len(mat)):
        if mat[j][i] == '#':
            flag = True
    if flag:
        answ.append(i)
for i in range(len(mat)):
    ans = [mat[i][j] for j in answ]
    print(''.join(ans))
        
