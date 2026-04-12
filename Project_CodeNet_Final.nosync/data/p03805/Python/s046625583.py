from itertools import permutations


def main():
    n, m = map(int, input().split())
    a = {tuple(int(i) - 1 for i in input().split()) for _ in range(m)}
    c = 0
    for per in permutations(range(1, n)):
        p = [0] + list(per)
        for i in range(n - 1):
            if (p[i], p[i + 1]) not in a and (p[i + 1], p[i]) not in a:
                break
        else:
            c += 1
    print(c)


if __name__ == '__main__':
    main()
