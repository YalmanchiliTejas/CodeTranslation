import sys


def _i(): return int(sys.stdin.readline().strip())


def main():
    x = _i()
    return "Yes" if x >= 30 else "No"


if __name__ == "__main__":
    print(main())
