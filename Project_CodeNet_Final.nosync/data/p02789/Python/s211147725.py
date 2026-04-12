def main():

    N, M = map(int, input().split())
    if N == M:
        return "Yes"
    return "No"


if __name__ == '__main__':
    print(main())
