# vim: set fileencoding=utf-8:


def main():
    H, W = map(int, raw_input().split())
    a = [0] * H
    for i in xrange(H):
        a[i] = list(raw_input())

    b = a
    # 列の圧縮
    for i in xrange(W):
        v = ""
        for j in xrange(len(a)):
            v += a[j][i]

        if set(v) == set(".#") or set(v) == set("#"):
            pass
        else:
            for j in xrange(len(a)):
                a[j][i] = "e"

    b = []
    for ele in a:
        val = ''.join(ele).replace("e", "")
        b.append(list(val))

    for i in xrange(len(b)):
        v = ""
        for j in xrange(len(b[0])):
            v += b[i][j]

        if set(v) == set(".#") or set(v) == set("#"):
            pass
        else:
            for j in xrange(len(b[0])):
                b[i][j] = "e"

    c = []
    for ele in b:
        val = ''.join(ele).replace("e", "")
        if val != '':
            print(val)


if __name__ == "__main__":
    main()
