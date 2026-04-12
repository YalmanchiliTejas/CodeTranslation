def main():
    n = int(input())
    hlis = list(map(int, input().split()))
    ans = 0
    highest = 0
    for i in range(n):
        if highest <= hlis[i]:
            ans += 1
            highest = hlis[i]
    print(ans)

if __name__ == "__main__":
    main()
