n = int(input())
h = list(map(int,input().split()))

ans = 0
H = h[0]

for i in range(n):
    if H <= h[i]:
        ans += 1
        H = h[i]
print(ans)