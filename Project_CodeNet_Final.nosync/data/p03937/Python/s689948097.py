def resolve():
    h, w = map(int, input().split())
    a = list(input() for _ in range(h))
    c = sum([ai.count("#") for ai in a])
    print("Possible" if c == h + w - 1 else "Impossible")


if __name__ == "__main__":
    resolve()
