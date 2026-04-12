def main():
    n = int(input())
    s = input().rstrip()
    k = int(input())
    c = s[k-1]
    for i in range(n):
        if s[i] != c:
            print("*", end="")
        else:
            print(s[i], end="")

if __name__ == "__main__":
    main()