n = int(input())
lis = list(map(int, input().split()))
ans = 0
m = 0
for i in range(n):
    m = max(m, lis[i])
    if m == lis[i]:
        ans += 1
print(ans)