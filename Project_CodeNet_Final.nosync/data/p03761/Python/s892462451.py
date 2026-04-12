from collections import defaultdict
from string import ascii_lowercase
from collections import Counter


def main():
    n = int(input())
    counter_list = [Counter(input()) for _ in range(n)]

    d = defaultdict(int)
    for a in ascii_lowercase:
        d[a] = 10 ** 10
    for a in ascii_lowercase:
        for c in counter_list:
            d[a] = min(d[a], c[a])

    print("".join([a * d[a] for a in ascii_lowercase]))

if __name__ == '__main__':
    main()
