def main():
    n, *s = map(str, open(0).read().split())

    a = [[t.count(chr(x)) for x in range(97, 97 + 26)] for t in s]
    b = []
    for i, t in enumerate(zip(*a)):
        m = min(t)
        if m > 0:
            c = chr(i + 97) * m
            b.append(c)
    ans = "".join(b)
    print(ans)


if __name__ == '__main__':
    main()
