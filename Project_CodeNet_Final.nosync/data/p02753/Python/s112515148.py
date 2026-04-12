def main():
    s = input().rstrip()
    if s[0] != s[1] or s[1] != s[2] or s[2] != s[0]:
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()