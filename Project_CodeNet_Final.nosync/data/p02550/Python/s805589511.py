def main():
    n, x, mod = map(int, input().split())
    a = x
    val = set()
    val_arr = []
    idx = {}
    rep = []
    init = []
    for i in range(n):
        if a in val:
           rep = val_arr[idx[a]:]
           init = val_arr[:idx[a]]
           break
        else:
            idx[a] = i
            val.add(a)
            val_arr.append(a)
            a = a ** 2 % mod
    if len(rep) > 0:
        ans = sum(init)
        ans += sum(rep) * ((n - len(init)) // len(rep))
        ans += sum(rep[:(n - len(init)) % len(rep)])
    else:
        ans = sum(val_arr)
    print(ans)


if __name__ == '__main__':
    main()
