n = int(input())
h = list(map(int, input().split()))

target = h[0]
ans = 1
for i in range(1,n):
    if h[i] >= target:
        ans+=1
        target = h[i]

print(ans)

