def main():
    R1, R2 = map(int, input().split())
    ans = R1 * R2 / (R1 + R2)
    print(ans)


if __name__ == "__main__":
    main()
