n = input()
arr = list(map(int, input().split()))

MOD = 10**9 + 7

res = 0
total = sum(arr)

# print(total)
# print(arr)
for a in arr:
    total -= a
    res += total * a % MOD
    # print(res)


print(res % MOD)