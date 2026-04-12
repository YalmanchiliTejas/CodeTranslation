def main():
    h, w = map(int, input().split())
    rows = set()
    cols = set()

    d = []
    for i in range(h):
        s = input()
        d.append(s)
        for j, c in enumerate(s):
            if c == '#':
                rows.add(i)
                cols.add(j)

    for i in range(h):
        if i not in rows:
            continue
        print(''.join(c for j, c in enumerate(d[i]) if j in cols))

main()
