import sys
import os


def main():
    if os.getenv("LOCAL"):
        sys.stdin = open("input.txt", "r")

    N = int(sys.stdin.readline().rstrip())
    S = str(sys.stdin.readline().rstrip())
    K = int(sys.stdin.readline().rstrip())
    target = S[K-1]

    for i in range(N):
        if S[i] != target:
            print("*", end="")
        else:
            print(target, end="")


if __name__ == '__main__':
    main()