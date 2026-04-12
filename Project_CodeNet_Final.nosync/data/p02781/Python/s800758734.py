
from functools import lru_cache

@lru_cache(maxsize=10000)
def calc(n, k):
    # print(n, k)

    if n < 10:
        if k > 1:
            # print('1:return 0')
            return 0
        elif k == 1:
            # print('2:return ' + str(n))
            return n
        else:
            return 1

    else:
        if k == 0:
            # print('5:return ')
            return 1#calc(n // 10, k)
        else:
            # print('6:return ')
            return calc(n // 10, k - 1) * (n % 10) + calc(n // 10 - 1, k - 1) * (9 - n % 10) + calc(n // 10, k)

n = int(input())
k = int(input())

print(calc(n, k))
