import sys
input = sys.stdin.readline


def main():
    S = input().strip()
    print("No") if S == "AAA" or S == "BBB" else print("Yes")


if __name__ == '__main__':
    main()
