import sys
import os


def main():
    if os.getenv("LOCAL"):
        sys.stdin = open("input.txt", "r")

    S = sys.stdin.readline().rstrip()

    print('Yes' if 'A' in S and 'B' in S else 'No')



if __name__ == '__main__':
    main()
