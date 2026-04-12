import sys

input = sys.stdin.readline


def main():
    n = int(input())
    h_list = [int(i) for i in input().split()]
    print(
        1 + len([i for i, h in enumerate(h_list[1:], start=1) if h >= max(h_list[:i])])
    )


if __name__ == "__main__":
    main()
