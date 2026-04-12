N = int(input(
))
X = list(map(int,input().split()))

X_sorted = sorted(X)

for i in range(N):
    x = X[i]
    if x < X_sorted[N//2]:
        print(X_sorted[N//2])
    else:
        print(X_sorted[N//2-1])
