import sys


def input():
    return sys.stdin.readline().rstrip()


def main():
    X =int(input())
    if X<30:
        print("No")
    else:
        print("Yes")


    pass


if __name__ == "__main__":
    main()
