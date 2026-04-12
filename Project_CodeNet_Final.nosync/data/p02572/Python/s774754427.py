# from pprint import pprint
# import math
# import collections

n = int(input())
# n, k = map(int, input().split(' '))
a = list(map(int, input().split(' ')))

MOD = 10 ** 9 + 7

wa = 0
for i in range(1, n):
    wa += a[i]

# print('wa', wa)

ans = 0
j = 1
for i in range(n - 1):
    ttl = a[i] * wa
    ans += ttl

    wa -= a[j]
    j += 1

    # print('new wa', wa)

print(ans % MOD)
