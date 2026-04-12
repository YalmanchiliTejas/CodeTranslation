def main():
    a,b,c,x,y = map(int, input().split())

    ans = 10**10
    for i in range(0,max(x,y)*2+2, 2):
        tmp = i*c
        x_count = i//2
        y_count = i//2
        tmp += max(0,x-x_count)*a + max(0,y-y_count)*b
        ans = min(ans, tmp)
    print(ans)


if __name__ == '__main__':
    main()
