n, x, m = map(int, input().split())

dic = {}
tmp = []

a = x
sum_a = x
for i in range(n - 1):
    if a in dic:
        tmp.append(sum_a)
        idx0 = dic[a] - 1
        idx1 = i - 1
        period = idx1 - idx0
        times = (n - 1 - idx0) // period
        res = (n - 1 - idx0) % period
        before = tmp[idx0]
        if idx0 >= 0:
            ans = tmp[idx0 + res] + (tmp[idx1] - tmp[idx0]) * times
            print(ans)
        elif idx0 < 0:
            if res > 0:
                ans = (tmp[idx1 + 1] - tmp[idx0 + 1]) * times + tmp[res - 1]
                print(ans)
            else:
                ans = (tmp[idx1 + 1] - tmp[idx0 + 1]) * times
                print(ans)
        break
    else:
        tmp.append(sum_a)
        dic[a] = i
        a = a ** 2 % m
        sum_a += a
else:
    print(sum_a)