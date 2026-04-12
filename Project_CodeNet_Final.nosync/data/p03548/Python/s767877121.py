def answer(x: int, y: int, z: int) -> int:
    return (x - z) // (y + z)


def main():
    x, y, z = map(int, input().split())
    print(answer(x, y, z))


if __name__ == '__main__':
    main()