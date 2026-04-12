n = int(input())
A = list(map(int,input().split()))

ans = 0
kage = 0

for i in range(n):
    if A[i] >= kage:
        ans += 1
    kage = max(kage, A[i])

print(ans)