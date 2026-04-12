def solve():
    N = int(input())
    Si = []
    for i in range(N):
        Si.append(sorted(input()))

    ds = []
    for s in Si:
        dic = {}
        for c in s:
            if c in dic:
                dic[c] += 1
            else:
                dic[c] = 1
        ds.append(dic)

    # print(ds)

    res = []
    for code in range(ord("a"), ord("z") + 1):
        c = chr(code)

        flag = True
        for d in ds:
            if c not in d:
                flag = False
                break

        if flag:
            m = 100000
            for d in ds:
                m = min(m, d[c])
            res.append((c, m))

    res = sorted(res, key=lambda x: x[0])

    answer = ""
    for r in res:
        answer += r[0] * r[1]

    return answer


if __name__ == '__main__':
    res = solve()
    print(res)
