N = int(input())
H = list(map(int, input().split()))

height = -1
ans = 0
for i in range(N):
    if H[i] >= height:
        ans += 1
        height = H[i]
    
print(ans)