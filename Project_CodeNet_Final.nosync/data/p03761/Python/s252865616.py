import sys
import collections


input = sys.stdin.readline


def main():
    N = int(input())

    C = []

    for i in range(N):
        S = input().strip()
        C.append(collections.Counter(S))

    for i in range(26):
        m = float("inf")
        for j in range(N):
            m = min(m, C[j][chr(ord('a') + i)])

        if m != float("inf"):
            print(chr(ord('a') + i) * m, end="")

    print()
    

if __name__ == '__main__':
    main()

