def main():
    s = input().rstrip()
    f = False
    for i in range(len(s)-1):
        if s[i] == "A" and s[i+1] == "C":
            f = True
    if f:
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()
