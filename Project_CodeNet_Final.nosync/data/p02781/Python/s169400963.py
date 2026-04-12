n = int(input())
k = int(input())
from math import log10, ceil


def helper(n, k):
    if k == 0:
        return 1
    if k >= 1 and n == 0:
        return 0

    keta = ceil(log10(n))
    if n == 10 ** (keta):
        keta += 1
    count = 0
    for tmp_keta in range(1, keta):
        if tmp_keta >= k:
            add_no = 9
            if k == 2:
                add_no *= 9 * (tmp_keta - 1)
            if k == 3:
                add_no *= 81 * int((tmp_keta - 2) * (tmp_keta - 1) / 2)
            count += add_no

    top = n // (10 ** (keta - 1))
    amari = n % (10 ** (keta - 1))
    if keta >= k:
        add_no = 1
        if k == 2:
            add_no *= 9 * (keta - 1)
        if k == 3:
            add_no *= 81 * int((keta - 2) * (keta - 1) / 2)
        count += add_no * (top - 1)
        count += helper(amari, k - 1)
    return count


print(helper(n, k))

# print(ceil(keta), top)

