n = int(input())
a = list(map(int, input().split()))
ans = 1
max_h = a[0]
for i in range(len(a)-1):
    if max_h <= a[i+1]:
        ans += 1
        max_h = a[i+1]
print(ans)
    