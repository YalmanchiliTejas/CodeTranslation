def calc_dynamic(n, x, m):
    # 結果を保持する辞書
    cal_result = {}

    # 初期値の設定
    cal_result[1] = x

    if n == 1:
        return x

    for i in range(1, n):
        cal_result[i+1] = cal_result[i] ** 2 % m

    #return cal_result[n]
    return sum(cal_result.values())

def calc_dynamic2(n, x, m):
    cal_result_0 = 0
    cal_result_1 = 0

    # 初期値の設定
    cal_result_0 = x
    total = x

    if n == 1:
        return x

    for i in range(1, n):
        cal_result_1 = cal_result_0 * cal_result_0 % m
        cal_result_0 = cal_result_1
        total += cal_result_1

    return total

def calc_dynamic3(n, x, m):
    # 結果を保持する辞書
    cal_result = {}
    cal_result_0 = 0
    cal_result_1 = 0
    loop_range = (0,0)

    # 初期値の設定
    cal_result_0 = x
    total = x

    if n == 1:
        return x

    for i in range(1, n):
        cal_result_1 = cal_result_0 * cal_result_0 % m
        cal_result_0 = cal_result_1
        total += cal_result_1
        if cal_result_1 in cal_result:
            loop_range = (cal_result[cal_result_1], i, cal_result_0, cal_result_1)
            break
        else:
            cal_result[cal_result_1] = (i, total)

    if i == n-1:
        return total

    hoge = i
    r = i - loop_range[0][0]
    v = total - loop_range[0][1]
    hoge += r
    total += v * ((n - hoge) // r)
    hoge += r * ((n - hoge) // r)
    #while hoge < n:
    #    total += v
    #    hoge += r

    cal_result_0 = loop_range[2]
    cal_result_1 = loop_range[3]
    for i in range(hoge-r+1, n):
        cal_result_1 = cal_result_0 * cal_result_0 % m
        cal_result_0 = cal_result_1
        total += cal_result_1

    return total

[n, x, m] = map(lambda x: int(x), input().split(" "))
print(calc_dynamic3(n, x, m))