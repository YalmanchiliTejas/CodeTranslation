def main():
    n = int(input())
    a = list(map(int, input().split()))
    ret = 0
    sum_list = [None] * n + [0]
    for i in range(n-1, -1, -1):
        sum_list[i] = sum_list[i+1] + a[i]
    for i in range(n):
        ret += a[i] * sum_list[i+1]
        ret %= 1000000007
    print(ret)

if __name__ == "__main__":
    main()
