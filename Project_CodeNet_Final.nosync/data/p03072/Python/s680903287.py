n = int(input())
a = list(map(int, input().split()))
ans = 0
for i in range(n):
    if i == 0:
        ans += 1
    elif max(a[:i]) <= a[i]:
        ans += 1
print(ans)