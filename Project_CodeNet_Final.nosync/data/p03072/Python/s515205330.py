N = int(input())
pre = -1
a = list(map(int, input().split()))
num = 0
for i in range(N):
    if pre <= a[i]:
        num += 1
    pre = max(pre, a[i])

print(num)