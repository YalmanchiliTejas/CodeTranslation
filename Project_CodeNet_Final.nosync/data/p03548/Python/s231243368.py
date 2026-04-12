def main(x, y, z):
    print((x - z) // (y + z))


if __name__ == "__main__":
    x, y, z = map(int, input().split())
    main(x, y, z)
