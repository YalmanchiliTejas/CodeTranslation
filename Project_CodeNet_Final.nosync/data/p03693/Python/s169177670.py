def main():
    A = [i for i in input().split()]
    S = "".join(A)
    N = int(S)
    print("YES" if N % 4 == 0 else "NO")


if __name__ == '__main__':
    main()
