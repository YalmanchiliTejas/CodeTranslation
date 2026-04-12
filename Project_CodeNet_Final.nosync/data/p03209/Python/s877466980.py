n, x = map(int, input().split())

level = [1]
p = [1]
for i in range(n):
    level.append(level[i]*2 + 3)
    p.append(p[i]*2 + 1)
#print(level)
#print(p)


def f(N, X):
    # 終了条件
    if N == 0:
        if X <= 0:
            return 0
        else:
            return 1
    mid = (level[N]+1)//2
    if X < mid:
        return f(N-1, X-1)
    elif X == mid:
        return p[N-1] + 1
    elif mid < X:
        return p[N-1] + 1 + f(N-1, X-mid)


ans = f(n, x)
print(ans)