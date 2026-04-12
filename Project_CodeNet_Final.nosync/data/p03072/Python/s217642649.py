N = int(input())
H = [int(i) for i in input().split()]

tmp = H[0]
ans = 1
for i in range(1, N):
    if tmp <= H[i]:
        ans += 1
        tmp = H[i]
        
print(ans)