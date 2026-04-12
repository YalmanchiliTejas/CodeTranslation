N = int(input())
H = list(map(int,input().split()))

ans = 0
high = 0
for i in range(N):
    if H[i] >= high :
        ans += 1
        high = H[i]
print(ans)