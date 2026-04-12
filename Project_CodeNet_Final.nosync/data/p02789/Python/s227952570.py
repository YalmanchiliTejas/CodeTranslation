
import sys


def solve(inp):
    (N, M) = map(int, inp.readline().strip().split(' '))

    if N == M:
        return "Yes"
    else:
        return "No"


def main():
    result = solve(sys.stdin)
    if result:
        print(result)


if __name__ == '__main__':
    main()
