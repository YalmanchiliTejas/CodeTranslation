def solve():
    n = int(input())
    arr = list(map(int, input().split()))
    arr_sum = sum(arr)
    arr_sum_sqr = arr_sum**2
    res = sum(i**2 for i in arr)
    res = (arr_sum_sqr - res) // 2
    print(res % (10**9+7))


def main():
    t = 1
    while t > 0:
        solve()
        t -= 1


main()