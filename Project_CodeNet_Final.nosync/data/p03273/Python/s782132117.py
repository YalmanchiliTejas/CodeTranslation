import numpy as np


def main():
    h, w = map(int, input().split())
    l = []
    for _ in range(h):
        a = list(input())
        if not '#' in a:
            continue
        l.append(a)
    l = np.array(l)
    m = np.rot90(l)
    n = []
    for a in m:
        if not '#' in a:
            continue
        n.append(a)
    ans = np.array(n)
    ans = np.rot90(ans, -1)
    for i in ans:
        print(*i, sep='')


if __name__ == "__main__":
    main()