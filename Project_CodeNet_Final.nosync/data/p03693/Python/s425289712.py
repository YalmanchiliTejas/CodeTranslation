import sys

def main():
    input = sys.stdin.readline
    A = list(map(int, input().split()))
    n = A[0] * 100 + A[1] * 10 + A[2]

    if n % 4 == 0:
        return 'YES'
    else:
        return 'NO'


if __name__ == '__main__':
    print(main())
