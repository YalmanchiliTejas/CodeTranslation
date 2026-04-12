N = int(input())
H  = list(map(int, input().split()))
ans = 0
max_h = 0
for i in range(N):
    if (max_h <= H[i]):
       max_h = H[i]
       ans += 1
print(ans)
