n = int(input())
arr = list(map(int, input().split()))
s = sum(arr)
ans = 0
for i in range(len(arr)):
    s -= arr[i]
    ans += (arr[i] * s)
print(ans % (10**9 + 7))
