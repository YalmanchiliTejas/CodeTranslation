LI = lambda: list(map(int, input().split()))

X = int(input())


def main():
    ans = "Yes" if X >= 30 else "No"
    print(ans)


if __name__ == "__main__":
    main()
