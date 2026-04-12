# ABC078B - ISU
def main():
    X, Y, Z = map(int, input().split())
    ans = (X - Z) // (Y + Z)
    print(ans)


if __name__ == "__main__":
    main()