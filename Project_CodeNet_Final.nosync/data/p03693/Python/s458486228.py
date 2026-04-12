def main():
    r, g, b = input().split()
    rgb = int("{}{}{}".format(r, g, b))
    if rgb % 4 == 0:
        ans = 'YES'
    else:
        ans = 'NO'

    print(ans)


if __name__ == "__main__":
    main()
