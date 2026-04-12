n = int(input())
arr = list(map(int, input().split()))

ans = 1
for i in range(1, n):
    if max(arr[:i]) <= arr[i]:
        ans += 1

print(ans)