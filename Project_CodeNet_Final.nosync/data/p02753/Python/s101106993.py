def main():
    char = input()
    count = 0
    chars_set = set()
    for c in char:
        if c not in chars_set:
            chars_set.add(c)
    if len(chars_set) > 1:
        print("Yes")
        return
    print("No")


if __name__ == "__main__":
    main()
