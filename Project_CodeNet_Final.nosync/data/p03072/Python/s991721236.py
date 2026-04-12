N = int(input())
H = list(map(int,input().split()))
ans = 1
temp = H[0]
for k in range(1,N):
    if temp <= H[k]:
        ans += 1
        temp = H[k]
print(ans)
