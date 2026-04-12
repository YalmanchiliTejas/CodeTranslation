#!python3

# input
N = int(input())


def main():
    ans = 800 * N - 200 * (N // 15)
    print(ans)


if __name__ == "__main__":
    main()
