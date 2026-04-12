def main():
    a, b, c, x, y = map(int, input().split())

    ans1 = x*a + y*b
    min_num = min(x, y)
    max_num = max(x, y)
    x, y = x-min_num, y-min_num
    ans2 = min_num*c*2 + max(x, 0)*a + max(y, 0)*b
    ans3 = max_num*c*2
    ans = min(ans1, ans2, ans3)
    print(ans)


if __name__ == "__main__":
    main()
