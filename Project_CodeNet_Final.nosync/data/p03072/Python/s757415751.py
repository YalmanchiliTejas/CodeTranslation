N = int(input())
H = list(map(int, input().split()))
ans = 1
for i in range(1,N):
    f = True
    for j in range(i):
        f = f and H[j]<=H[i]
    if f:
        ans += 1
print(ans)