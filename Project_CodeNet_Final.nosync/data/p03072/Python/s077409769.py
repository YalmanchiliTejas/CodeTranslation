
n = int(input())
h = list(map(int,input().split()))

ans = 0
max_H = 0
for i in range(n):
    if max_H <= h[i]:
        ans += 1
        max_H = h[i]
print(ans)
