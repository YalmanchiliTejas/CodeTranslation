n = int(input())
h = list(map(int,input().split()))

ans = 1
height = h[0]
for i in range(1,n):
    if(height <= h[i]):
        ans += 1
        height = h[i]
print(ans)