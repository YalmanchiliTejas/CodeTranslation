def main():
    x, y, z = map(int, input().split())
    x = x - z
    ans = x // (y+z)
    print(ans)


if __name__ == "__main__":
    main()
