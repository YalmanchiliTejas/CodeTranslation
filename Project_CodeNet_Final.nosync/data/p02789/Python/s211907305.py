import sys


def main():
    tmp = input().split(" ")
    n = int(tmp[0])
    m = int(tmp[1])
    if n == m:
        print("Yes")
    else:
        print("No")


if __name__ == '__main__':
    input = sys.stdin.readline
    main()
