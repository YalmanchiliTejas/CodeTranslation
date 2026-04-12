N = int(input())
H = [int(n) for n in input().split()]
ans = 1
for i in range(1,N):
    if max(H[0:i]) <= H[i]:
        ans += 1
print(ans)