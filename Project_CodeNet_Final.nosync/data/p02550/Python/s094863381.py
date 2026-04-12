def main():
    n, x, m = map(int, input().split())
    dic = {}
    p = 0
    while not x in dic:
        p += 1
        dic[x] = p
        x = (x**2) % m
    if n <= p:
        ans = 0
        for ky in dic.keys():
            if dic[ky] <= n:
                ans += ky
        print(ans)
    else:
        ans = 0
        for ky in dic.keys():
            ans += ky
        n -= p
        q = dic[x]
        ln = p - q + 1
        tmp = 0
        for ky in dic.keys():
            if q <= dic[ky] <= p:
                tmp += ky
        tmp *= n // ln
        ans += tmp
        n %= ln
        for ky in dic.keys():
            if q <= dic[ky] < q + n:
                ans += ky
        print(ans)

if __name__ == "__main__":
    main()