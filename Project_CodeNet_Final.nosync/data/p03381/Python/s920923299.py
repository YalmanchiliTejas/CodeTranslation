N = int(input())
X_list = list(map(int, input().split()))

X_list_min = sorted(X_list)

for i in range(N):
    if X_list_min[N//2-1] >= X_list[i]:
        print(X_list_min[N//2])
    else:
        print(X_list_min[N//2-1])