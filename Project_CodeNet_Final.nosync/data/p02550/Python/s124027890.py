n, x, m = list(map(int, input().split()))

count = 0

# table2jou = []
# for mi in range(m + 1):
#     table2jou.append(pow(mi, 2))

# tablef = []
# for mi in range(m + 1):
#     # tablef.append(table2jou[mi] % m)
#     tablef.append(pow(mi, 2, m))

is_used = [0] * (m + 1)

count = x
pre_an = x
his = [x]
for ni in range(2, n + 1):
    # an = tablef[pre_an]
    an = pow(pre_an, 2, m)
    if is_used[an] == 1:
        leftnum = n - ni + 1
        start = his.index(an)
        end = leftnum % (len(his) - start) + start
        loopnum = leftnum // (len(his) - start)
        count = count + sum(his[start: end])
        count = count + sum(his[start:]) * loopnum
        break
    his.append(an)
    is_used[an] = 1
    count = count + an
    pre_an = an

print(count)
