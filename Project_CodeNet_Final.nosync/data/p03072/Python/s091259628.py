N = int(input())
H = [int(h) for h in input().split()]

ans = 0
temp_max = H[0]
for i in range(N):
    if temp_max <= H[i]:
        ans += 1
        temp_max = H[i]
        
print(ans)