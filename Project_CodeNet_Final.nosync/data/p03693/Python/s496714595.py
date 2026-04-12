def test():
    x = input().split()
    str = int("".join(x))
    print("YES" if str % 4 == 0 else "NO")


if __name__ == "__main__":
    test()
