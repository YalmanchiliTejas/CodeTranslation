def main():
    from collections import Counter

    n = list(str((input())))
    dic = Counter(n)
    if len(dic) == 1:
        print("No")
    else:
        print("Yes")


if __name__ == "__main__":
    main()