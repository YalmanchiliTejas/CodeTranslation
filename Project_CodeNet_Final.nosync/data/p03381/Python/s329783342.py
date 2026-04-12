N = int(input())
X_list = list(map(int, input().split()))
median = N//2

med = sorted(X_list)[median-1:median+1]
for i in range(N):
    if X_list[i] < med[1]:
        print(med[1])
    else:
        print(med[0])
