def main():
    s = list(input())
    s_set = set(s)

    if len(s_set) == 1:
        print('No')
    else:
        print('Yes')


if __name__ == "__main__":
    main()
