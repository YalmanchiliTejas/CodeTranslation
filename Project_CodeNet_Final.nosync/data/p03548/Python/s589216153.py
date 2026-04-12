import sys
input = sys.stdin.readline
# sys.setrecursionlimit(100000)


def main():
    x, y, z = [int(i) for i in input().strip().split()]
    x = x - z
    ans = x // (y + z)
    print(ans)

    return


if __name__ == "__main__":
    main()
