import sys
# sys.setrecursionlimit(100000)


def input():
    return sys.stdin.readline().strip()


def input_int():
    return int(input())


def input_int_list():
    return [int(i) for i in input().split()]


def main():
    r, g, b = input().split()
    if int(r + g + b) % 4 == 0:
        print("YES")
    else:
        print("NO")
    return


if __name__ == "__main__":
    main()
