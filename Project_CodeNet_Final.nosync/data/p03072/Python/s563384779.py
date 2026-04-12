N = int(input())
arr = list(map(int, input().split()))

ans = 0
top = 0
for i in range(N):
    if arr[i] >= top:
        ans += 1
        top = arr[i]
print(ans)