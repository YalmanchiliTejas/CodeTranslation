def main():
    while True:
        n = int(input())
        if n == 0:break
        a = []
        for i in range(n):
            a.append(int(input()))
        a.sort()
        sum = 0
        for i in range(1,n-1):sum+=a[i]
        print(sum//(n-2))


if __name__ == '__main__':
    main()


