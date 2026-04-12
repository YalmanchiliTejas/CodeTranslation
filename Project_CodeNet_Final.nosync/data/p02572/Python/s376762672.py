n = int(input())
MOD = 10 ** 9 + 7
a = [int(i) for i in input().split()]


total = sum(a) % MOD
kotae = 0
for i in range(n-1):
    total -= a[i]
    if(total < 0):
        total += MOD
    kotae += a[i] * total
    kotae = kotae % MOD


print(kotae)