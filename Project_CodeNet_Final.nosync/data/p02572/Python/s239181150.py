

def main():
    n = int(input().strip())
    l = list(map(int, input().split()))
    stack = [0]*n

    totstack = 0
    for i in range(n-1):
        totstack += l[n-i-1]
        stack[n-i-2] = totstack

    tot = 0
    for i in range(n):
        tot += (l[i] * (stack[i] % (10 ** 9 + 7))) % (10 ** 9 + 7)

    print(tot % (10 ** 9 + 7))


if __name__ == "__main__":
    main()

