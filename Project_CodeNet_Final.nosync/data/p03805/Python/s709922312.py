N, M = map(int, input().split())
x = [[] for i in range(N)]
for i in range(M):
    a, b = map(int, input().split())
    x[a-1].append(b-1)
    x[b-1].append(a-1)

flag = [False]*N
flag[0] = True
res = 0

def f(n):
    global res
    for fl in flag:
        if not fl:
            break
    else:
        res += 1
        return
    for i in x[n]:
        if flag[i]:
            continue
        flag[i] = True
        f(i)
        flag[i] = False
    return

f(0)
print(res)