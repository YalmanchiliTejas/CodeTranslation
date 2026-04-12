def solve(string):
    h, w, *a = string.split()
    h = int(h)
    w = int(w)
    rows = [sum([_c == "#" for _c in _a]) for _a in a]
    cols = [sum([_a[i] == "#" for _a in a]) for i in range(w)]
    ans = "\n".join(
        "".join([_c for __f, _c in zip(cols, _a) if __f]) for _f, _a in zip(rows, a) if _f)
    return ans


if __name__ == '__main__':
    n, w = map(int, input().split())
    print(solve('{} {}\n'.format(n, w) + '\n'.join([input() for _ in range(n)])))
