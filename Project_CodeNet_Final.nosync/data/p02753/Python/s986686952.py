def main():
    S = input()
    if len(set(s for s in S)) == 1:
        print("No")
    else:
        print("Yes")


if __name__ == '__main__':
    main()
