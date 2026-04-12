N = int(input())
s = input()

ans = ['SS', 'SW', 'WS', 'WW']
s += s[0]
for i in range(4):
    for j in range(1, N+1):
        if ans[i][j] == 'S':
            if s[j] == 'o':
                ans[i] += ans[i][j-1]
            else:
                if ans[i][j-1] == 'S':
                    ans[i] += 'W'
                else:
                    ans[i] += 'S'
        else:
            if s[j] == 'x':
                ans[i] += ans[i][j-1]
            else:
                if ans[i][j-1] == 'S':
                    ans[i] += 'W'
                else:
                    ans[i] += 'S'

    if ans[i][0] == ans[i][-2] and ans[i][1] == ans[i][-1]:
        print(ans[i][:-2])
        exit()

print(-1)