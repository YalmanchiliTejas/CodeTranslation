# import numpy as np
# import itertools as it

n = int(input())
a = list(map(int, input().split()))

res = 0
for i in range(n):
    res += a[i] * a[i]

ans = sum(a) * sum(a)
print(((ans - res)//2) % (10 ** 9 + 7))


# sum = 0
# for i in range(n):
#     sum += 1 / a[i]
#print(sum)

# ans = int(sum * np.prod(a))
# print(ans % (10 ** 9 + 7))
