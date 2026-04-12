def main():
    n = int(input())
    s = input()
    k = int(input())
    ans = ""
    sk = s[k - 1]

    for ch in s:
        if ch == sk:
            ans += sk
        else:
            ans += "*"

    print(ans)


if __name__ == "__main__":
    main()
