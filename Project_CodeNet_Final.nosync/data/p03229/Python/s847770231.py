def cul(low, high):
    high = high[::-1]
    lists = []
    if len(low) > len(high):
        low.insert(0, low[-1])
        low = low[:-1]
        lists.append(low[0])
        for _l, _h in zip(low[1:], high):
            lists.append(_h)
            lists.append(_l)
    elif len(low) < len(high):
        high.insert(0, high[-1])
        high = high[:-1]
        lists.append(high[0])
        for _l, _h in zip(low, high[1:]):
            lists.append(_l)
            lists.append(_h)
    else:
        low.insert(0, low[-1])
        low = low[:-1]
        for _l, _h in zip(low, high):
            lists.append(_l)
            lists.append(_h)
    ans = 0
    for _p, _n in zip(lists, lists[1:]):
        ans += abs(_n - _p)
    return ans


n = int(input())
a = sorted([int(input()) for _ in range(n)])
if len(a) % 2 == 1:
    lower = a[:len(a) // 2 + 1]
    higher = a[len(a) // 2 + 1:]
    first = cul(lower, higher)
    lower = a[:len(a) // 2]
    higher = a[len(a) // 2:]
    second = cul(lower, higher)
    print(max(first, second))
else:
    lower = a[:len(a) // 2]
    higher = a[len(a) // 2:]
    print(cul(lower, higher))
