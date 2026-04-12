import sys

def main():
    input = sys.stdin.readline
    N = int(input())
    S = str(input().strip())
    K = int(input())

    c = S[K-1]
    ans = ''
    for s in S:
        if s == c:
            ans += s
        else:
            ans += '*'

    return ans


if __name__ == '__main__':
    print(main())
