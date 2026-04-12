n, m = map(int, input().split())
L = [[] for i in range(n)]

for i in range(m):
    a, b = map(int, input().split())
    L[a-1].append(b-1)
    L[b-1].append(a-1)

ans = 0

def f(t, history):
    his = history[:]
    his[t] += 1
    global ans
    if sum(his)==n:
        ans += 1
    else:
        for i in L[t]:
            if his[i]==0:
                f(i, his)

f(0, [0]*n)
print(ans)
