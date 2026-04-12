def main():

    a, b, c, x, y = map(int,input().split())
    ans = 0
    if a + b > c * 2:
        ans += c * 2 * min(x, y)
        if x < y:
            ab = b * (y-x)
        else:
            ab = a * (x-y)
        cc = c * 2 * max(x, y)
        ans = min(ans + ab, cc)
    else:
        ans = a * x + b * y
    print(ans)
if __name__ =='__main__':
    main()
