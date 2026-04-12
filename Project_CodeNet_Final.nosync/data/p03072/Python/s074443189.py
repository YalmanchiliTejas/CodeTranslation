n = int(input())
a = list(map(int, input().split()))
m = a[0]
cnt = 0
for i in range(n):
    m = max(m, a[i])
    if m <= a[i]:
        cnt += 1
print(cnt)