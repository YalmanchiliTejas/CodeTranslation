import string
from collections import Counter


# least common char count
def lccc(c, cnts):
    m = 51 # s <= 50
    for cc in cnts:
        if (not c in cc):
            return 0
        if (cc[c] < m):
            m = cc[c]
    return m


def main():
    counter = dict()

    n = int(input())
    cnts = [Counter(list(input())) for i in range(n)]
    for c in list(string.ascii_lowercase):
        counter[c] = lccc(c, cnts)

    print("".join([k * counter[k] for k in sorted(counter.keys())]))


if __name__ == '__main__':
    main()
