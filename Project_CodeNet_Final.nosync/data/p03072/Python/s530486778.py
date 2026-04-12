N = int(input())
Height = list(map(int, input().split()))
ans = 1
h_w = Height[0]

for i in range(1, N):
    if (h_w <= Height[i]):
        ans += 1
    
    h_w = max(h_w, Height[i])

print(ans)