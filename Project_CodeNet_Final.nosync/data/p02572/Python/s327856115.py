if __name__ == "__main__":
    n = int(input())

    arr = [int(x) for x in input().split()]
    s1 = sum(arr)
    s2 = sum((x * x for x in arr))

    ans = s1*s1 - s2

    if ans % 2 != 0:
        ans += 10**9+7

    ans //= 2

    print(ans % (10**9 + 7))