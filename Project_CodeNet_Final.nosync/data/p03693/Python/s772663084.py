def resolve():
    rgb = int(input().replace(" ", ""))
    print("YES" if rgb % 4 == 0 else "NO")


if __name__ == "__main__":
    resolve()
