def main():
    n, x, m = map(int, input().split())
    a = x
    s = a
    seen = {a}
    seq = [a]
    for i in range(n - 1):
        if a == pow(a, 2, m):
            print(s + a * (n - i - 1))
            return
        else:
            a = pow(a, 2, m)
            if a in seen:
                si = seq.index(a)
                sl = i - si + 1
                ps = s - sum(seq[:si])
                ln = (n - i - 1) // sl
                lm = (n - i - 1) % sl
                print(s + ps * ln + sum(seq[si:si + lm]))
                return
            s += a
            seen.add(a)
            seq.append(a)
    print(s)


if __name__ == '__main__':
    main()
