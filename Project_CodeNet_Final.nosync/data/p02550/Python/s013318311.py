N, X, M = map(int, input().split())

ans = 0
flag = [0]*(10**5 + 2)
lst = [X]

for i in range(N):
    X = (X**2)%M

    if flag[X] == 1:
        break

    flag[X] = 1
    lst.append(X)

preindex = lst.index(X)

preloop = lst[:preindex]
loop = lst[preindex:]

loopnum = (N - len(preloop))//len(loop)
loopafternum = (N - len(preloop))%len(loop)

ans = sum(preloop) + sum(loop)*loopnum + sum(loop[:loopafternum])
print(ans)