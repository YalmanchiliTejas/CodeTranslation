N = int(input())
a = list(map(int, input().split()))
cnt = 0
max = 0
for i in range(N):
    if max <= a[i]:
        cnt += 1
        max = a[i]
print(cnt)