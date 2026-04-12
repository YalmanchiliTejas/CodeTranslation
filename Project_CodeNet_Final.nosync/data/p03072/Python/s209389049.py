def main():
    N = int(input())
    A = [int(n) for n in input().split()]
    m = -1
    res = 0
    for a in A:
        if a >= m:
            m = a
            res += 1
    print(res)
if __name__ == "__main__":
    main()