n, x, m = map(int, input().split())
init, cr = x, x
hist = [m+1, x]
for idx in range(2, n + 1):
    cr = (cr ** 2) % m
    if cr in hist:
        idx_bef = hist.index(cr)
        remains = n - idx + 1
        ans = sum(hist[1:])
        sum_period = sum(hist[idx_bef:])
        period_num = idx - idx_bef
        ans += sum_period * (remains // period_num)
        ans += sum(hist[idx_bef: idx_bef + remains % period_num])
        print(ans)
        exit()
    else:
        hist.append(cr)
print(sum(hist[1:]))
