N = int(input())
a = list(map(int, input().split()))
m = a[0]
c = 0
for i in range(N):
    m = max(m, a[i])
    if m <= a[i]:
        c += 1
print(c)