n = int(input())
arr = list(map(int, input().split()))
big = arr[0]
ans = 0
for i in range(n):
    if big <= arr[i]:
        ans += 1
        big = arr[i]
print(ans)