def main2():
    H, W = map(int, input().split())

    count = 0
    for i in range(H):
        count += input().count("#")

    if count == (H + W - 1):
        print("Possible")
    else:
        print("Impossible")

if __name__ == "__main__":
    main2()