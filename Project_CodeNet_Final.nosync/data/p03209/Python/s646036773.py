def cin():
    in_ = list(map(int,input().split()))
    if len(in_) == 1:  return in_[0]
    else:  return in_

N, X = cin()
a = [0 for _ in range(N)] # 全体の枚数
p = [0 for _ in range(N)] # パティの枚数
a[0] = 1
p[0] = 1

for i in range(1, N):
    a[i] = 2 * a[i - 1] + 3
    p[i] = 2 * p[i - 1] + 1
    
def f(N, X):
    if N == 0:  
        if X <= 0: return 0
        else:  return 1
    if X <= 1 + a[N - 1]:  return f(N - 1, X - 1)
    return 1 + p[N - 1] + f(N - 1, X - 2 - a[N - 1])

ans = f(N, X)
print(ans)