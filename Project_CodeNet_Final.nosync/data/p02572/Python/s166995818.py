n = int(input())
a = list(map(int, input().split()))
mod = 1000000007
res = 0
a_sum = sum(a)

for i in range(n - 1):
    main = a[i]
    a_sum = a_sum - main
    res =  (res + main * a_sum % mod) % mod
print(res)