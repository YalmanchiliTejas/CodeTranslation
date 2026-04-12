# /usr/bin/env python3


def judge(s):
    return s != "AAA" and s != "BBB"


def main():
    s = input()
    print("Yes" if judge(s) else "No")


if __name__ == "__main__":
    main()
