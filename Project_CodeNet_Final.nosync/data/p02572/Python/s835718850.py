def main():
    n = int(input())
    a = list(map(int, input().split(" ")))
    total_a = sum(a)
    total = 0
    for i in range(n):
        total_a-=a[i]
        total+=(a[i] * total_a)%(10**9+7)
    print(total%(10**9+7))

if __name__=="__main__":
    main()
