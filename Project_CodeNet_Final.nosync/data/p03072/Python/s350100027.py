n = int(input())
a = []
a = input().split()
ans = 1
for i in range(n):
    a[i] = int(a[i])
for i in range(1,n):
    if a[i] >= max(a[:i]):
        ans += 1
print(ans)