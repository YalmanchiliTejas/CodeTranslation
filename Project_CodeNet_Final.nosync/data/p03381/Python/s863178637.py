N = int(input())
X = list(map(int, input().split()))

X_sorted = sorted(X)
first_half_median = X_sorted[N // 2 - 1]
last_half_median = X_sorted[N // 2]

for i in range(N):
    if X[i] <= first_half_median:
        print(last_half_median)
    else:
        print(first_half_median)