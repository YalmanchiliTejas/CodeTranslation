n = int(input())
arr = list(map(int, input().split()))
mod = 10**9 + 7

# 愚直
# res = 0
# for i in range(n-1):
#     for j in range(i+1, n):
#         res += arr[i] * arr[j]
#         res %= mod

# print(res)

s = sum(arr)
res = 0
for a in arr:
    s -= a
    res += a * s
    res %= mod

print(res)
