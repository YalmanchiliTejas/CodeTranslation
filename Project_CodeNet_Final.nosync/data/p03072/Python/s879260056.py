N = int(input())
H = list(map(int,input().split()))

max = 0
ans = 0
for i in range(N):
    if H[i] >= max:
        ans += 1
        max = H[i]

print(ans)