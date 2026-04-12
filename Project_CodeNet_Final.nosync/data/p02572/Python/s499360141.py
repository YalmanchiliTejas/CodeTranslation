def main():
    n = int(input())
    arr = list(map(int, input().split()))
    mod = 10 ** 9 + 7
    sq = sum(num*num for num in arr)
    S = sum(arr)
    print(((S*S-sq)//2)%mod)

if __name__ == "__main__":
    main()