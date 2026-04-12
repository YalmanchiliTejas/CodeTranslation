def main():
    N = int(input())
    S = input()
    K = int(input())
    ans = ""
    for c in S:
        if c == S[K-1]:
            ans += c
        else:
            ans += "*"
    print(ans)


if __name__ == "__main__":
    main()
