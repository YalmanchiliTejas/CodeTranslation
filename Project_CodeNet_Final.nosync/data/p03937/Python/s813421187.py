def main():
    H, W = map(int, input().split())
    A = [input() for i in range(H)]

    cnt = 0
    for a in A:
        cnt += a.count("#")

    if cnt == H + W - 1:
        print("Possible")
    else:
        print("Impossible")


if __name__ == "__main__":
    main()