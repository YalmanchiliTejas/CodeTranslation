import sys
def input(): return sys.stdin.readline().strip()
# sys.setrecursionlimit(100000)


def main():
    N = int(input().strip())
    if N >= 30:
        print("Yes")
    else:
        print("No")

    return


if __name__ == "__main__":
    main()
