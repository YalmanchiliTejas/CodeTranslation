n, x = map(int, input().split())
# レベルごとの全体の枚数、パティの枚数を求める
a, p = [1], [1]
for i in range(n):
    a.append(2*a[i] + 3)
    p.append(2*p[i] + 1)
    
def f(n, x):
    if n == 0:
        return 0 if x <= 0 else 1
    # 3つの場合分け
    mid = (a[n]+1)/2
    if x == mid:
        return 1 + p[n-1]
    elif x < mid:
        return f(n-1, x-1)
    elif x > mid:
        return f(n-1, x-mid) + 1 + p[n-1]

print(f(n, x))