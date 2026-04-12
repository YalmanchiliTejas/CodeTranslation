"""
AtCoder :: Beginner Contest 174 :: Air Conditioner
https://atcoder.jp/contests/abc174/tasks/abc174_a
"""
import sys


def main():
    """Main program."""
    temp = int(sys.stdin.readline())
    if temp >= 30:
        print("Yes")
    else:
        print("No")


if __name__ == '__main__':
    main()
