from sys import stdin


def main():
    _ = int(stdin.readline().rstrip())
    Hs = [int(x) for x in stdin.readline().rstrip().split()]
    print(len([x for i, x in enumerate(Hs) if i == 0 or max(Hs[:i]) <= x]))


if __name__ == "__main__":
    main()
