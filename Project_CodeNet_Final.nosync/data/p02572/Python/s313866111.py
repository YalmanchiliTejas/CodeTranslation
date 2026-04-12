n = int(input())
arr = list(map(int, input().split()))

MOD = 10**9 + 7

ans = 0
sum_arr = sum(arr)

for x in arr:
    sum_arr -= x
    ans += x * sum_arr
    ans %= MOD

print(ans)