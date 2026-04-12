N = input()
arr = list(map(int,input().split(" ")))
MOD = int(1e9+7)
sum_arr = sum(arr) % MOD
res = 0
for a in arr:
    sum_arr = (sum_arr-a)%MOD
    res = (res+ sum_arr*a)%MOD
print(res)