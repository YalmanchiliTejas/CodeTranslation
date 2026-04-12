from bisect import bisect_right
import sys
input = sys.stdin.readline


def main():
    N = int(input())
    A = [int(input()) for _ in range(N)]
    stream = []
    for a in A:
        idx = bisect_right(stream, -a)
        if idx < len(stream):
            stream[idx] = -a
        else:
            stream.append(-a)

    print(len(stream))


if __name__ == "__main__":
    main()
