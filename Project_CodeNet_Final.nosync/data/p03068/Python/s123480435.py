def main(n: int, s: str, k: int):
    rp = s[k - 1]

    for s in s:
        if s != rp:
            print("*", end="")
        else:
            print(rp, end="")


if __name__ == "__main__":
    n = int(input())
    s = input()
    k = int(input())

    main(n, s, k)
