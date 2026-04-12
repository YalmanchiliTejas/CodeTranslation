N = int(input())
X = [int(_) for _ in input().split()]

xs = sorted(X)

m1 = xs[N // 2 - 1]
m2 = xs[N // 2]

for i in range(N):
    if X[i] <= m1:
        print(m2)
    else:
        print(m1)
