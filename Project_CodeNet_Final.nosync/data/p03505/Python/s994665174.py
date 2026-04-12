def main():
    K, A, B = map(int, input().split())
    if K <= A:
        print(1)
        return
    if A <= B:
        print(-1)
        return
    ans = max(0, -(-(K-A)//(A-B))) * 2 + 1
    print(ans)


if __name__ == "__main__":
    main()
