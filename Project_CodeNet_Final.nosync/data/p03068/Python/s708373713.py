import sys


def main():
    N = int(sys.stdin.readline())
    S = sys.stdin.readline().strip()
    K = int(sys.stdin.readline())
    s = S[K-1]
    result = ""
    for i in list(S):
        if i == s:
            result = result + i
        else:
            result = result + "*"
    print(result)


if __name__ == "__main__":
    main()
