def main():
    x, y, z = map(int, input().split())

    for i in range(1, 10 ** 5 + 1):
        if (z + y) * i + z > x:
            print(i - 1)
            exit()


if __name__ == "__main__":
    main()
