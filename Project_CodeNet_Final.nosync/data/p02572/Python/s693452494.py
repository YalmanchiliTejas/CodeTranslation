def main():
    n = int(input())
    a = []
    sum = 0             #longの気持ち
    ans = 0             #long long の気持ち
    mod = 1_000_000_000 + 7
    x = list(map(int, input().split()))
    for i in range(n):
        sum += x[i]           
        a.append(x[i])
    
    for i in range(n):
        sum -= a[i]
        ans += sum * a[i]
        ans %= mod
    print(ans)

if __name__ == "__main__":
    main()

    