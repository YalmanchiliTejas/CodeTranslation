# A - AC or WA
def main():
    N, M = map(int, input().split())
    is_correct = N == M
    print("Yes" if is_correct else "No")


if __name__ == "__main__":
    main()
