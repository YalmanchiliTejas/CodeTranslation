def solve(n, x, m):
    result = [x]
    checked = [0] * m
    checked[x] = 1
    while len(result) < n:
        x = x * x % m
        if checked[x] > 0:
            break
        result.append(x)
        checked[x] = len(result)
    else:
        return sum(result)

    l = len(result)
    i = checked[x]
    before_len = i - 1
    loop_len = l - i + 1
    loop_sum = sum(result[before_len:])
    d, e = divmod(n - before_len, loop_len)
    ans = sum(result[:before_len]) + loop_sum * d + sum(result[before_len:before_len + e])
    return ans


n, x, m = map(int, input().split())

print(solve(n, x, m))
