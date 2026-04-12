N = int(input())
H = list(map(int, input().split()))
ans = 0
for i in range(N):
    if all([True if H[jk] <= H[i] else False for jk in range(i)]):
        ans += 1
print(ans)