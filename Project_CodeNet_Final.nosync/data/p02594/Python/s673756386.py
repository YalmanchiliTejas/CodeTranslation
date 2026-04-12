# import sys
# readline = sys.stdin.readline
# generator = (readline().strip() for _ in range(N))

# N, M = map(int, input().split())
# As = list(map(int, input().split()))
# queries = (input() for _ in range(N))


def solve():
    temperature = int(input())
    return ['No', 'Yes'][temperature >= 30]


def main():
    print(solve())


if __name__ == "__main__":
    main()
