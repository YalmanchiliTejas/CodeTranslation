def func(lv, id):
    sz = 4 * 2 ** lv - 3
    num = 2 * 2 ** lv - 1
    mid = (sz + 1) / 2
    if id < 1 or id > sz:
        return 0
    return [0, func(lv - 1, id - 1), num / 2 + 1, func(lv - 1, id - sz / 2 - 1) + num / 2 + 1, num, 1][(id > 1) + (id >= mid) + (id > mid) + (id >= sz) + (lv == 0) * 3]

print func(*map(int, raw_input().split()))