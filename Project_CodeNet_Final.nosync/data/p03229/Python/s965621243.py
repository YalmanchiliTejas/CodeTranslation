def tpbc_2018_c():
    n = int(input())
    a = [int(input()) for _ in range(n)]
    a.sort()
    low = a[:len(a) // 2]
    high = a[len(a) // 2:]
    if len(a) % 2 == 0:
        return 2 * (sum(high) - sum(low)) + max(low) - min(high)
    else:
        low2 = a[:len(a) // 2 + 1]
        high2 = a[len(a) // 2 + 1:]
        return max(2 * (sum(high) - sum(low)) - high[0]-high[1],2 * (sum(high2) - sum(low2))+low2[-2]+low2[-1])


print(tpbc_2018_c())