n,x = list(map(int, input().split()))

ans = [1]
pat = [1]
a = 1
p = 1
for i in range(n):
    ans.append(a*2 + 3)
    pat.append(p*2 + 1)
    a = a*2 + 3
    p = p*2 + 1

def f(N, X):
    if N == 0:
        return 0 if X <= 0 else 1
    elif X <= 1 + ans[N-1]:
        return f(N-1, X-1)
    elif X == 2 + ans[N-1]:
        return pat[N-1] + 1
    elif X <= 2 + 2*ans[N-1]:
        return pat[N-1] + 1 + f(N-1, X-2-ans[N-1])
    else:
        return 2*pat[N-1] + 1

print(f(n, x))