N = int(input())
s = list(input())
if s[1] == 'o':
    ans = [['S', 'S', 'S'], ['W', 'S', 'W'], ['S', 'W', 'W'], ['W', 'W', 'S']]
else:
    ans = [['S', 'S', 'W'], ['W', 'S', 'S'], ['S', 'W', 'S'], ['W', 'W', 'W']]

for i in range(4):
    for j in range(2, N-1):
        if s[j] == 'o':
            n0, n1 = 'S', 'W'
        else:
            n0, n1 = 'W', 'S'
        if ans[i][j-1] == 'S':
            if ans[i][j] == 'S':
                ans[i].append(n0)
            else:
                ans[i].append(n1)
        else:
            if ans[i][j] == 'S':
                ans[i].append(n1)
            else:
                ans[i].append(n0)
    
    Realize = True
    for j in [-1, 0]:
        if s[j] == 'o':
            if ans[i][j] == 'S':
                if ans[i][j-1] != ans[i][j+1]:
                    Realize = False
                    break
            else:
                if ans[i][j-1] == ans[i][j+1]:
                    Realize = False
                    break
        else:
            if ans[i][j] == 'S':
                if ans[i][j-1] == ans[i][j+1]:
                    Realize = False
                    break
            else:
                if ans[i][j-1] != ans[i][j+1]:
                    Realize = False
                    break
    if Realize:
        print(''.join(ans[i]))
        exit()
print(-1)