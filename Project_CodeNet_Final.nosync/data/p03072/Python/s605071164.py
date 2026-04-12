n = int(input())
h = list(map(int,input().split()))
ans = 1
x = h[0]
for i in range(1,n):
    if h[i] >= x:
        ans += 1
        x = h[i]
print(ans)