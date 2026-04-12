N = int(input())
H = list(map(int,input().split()))
high = 0
ans = 0
for i in range(N):
    if high <= H[i]:
        high = H[i]
        ans += 1
print(ans)