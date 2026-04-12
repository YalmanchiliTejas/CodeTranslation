def count_hotels(n, hs):
    res = 1 + sum(all(hs[j] <= hs[i] for j in range(i)) for i in range(1, n))
    return res


def main():
    n = int(input())
    hs = [int(h) for h in input().split()]
    print(count_hotels(n, hs))


if __name__ == "__main__":
    main()