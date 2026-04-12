def main():
    n = int(input())
    inlis = list(map(int, input().split()))

    total = sum(inlis)

    tmp = 0

    for i in range(n):
        total -= inlis[i]
        tmp += inlis[i] * total 
        tmp %= (10**9 + 7)
    
    ans = tmp % (10**9 + 7)
    print(ans)


if __name__ == "__main__":
    main()