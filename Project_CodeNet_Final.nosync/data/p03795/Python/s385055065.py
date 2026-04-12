import sys
input = sys.stdin.readline

def main():
    N = int(input())

    print(800 * N - 200 * (N//15))


if __name__ == "__main__":
    main()