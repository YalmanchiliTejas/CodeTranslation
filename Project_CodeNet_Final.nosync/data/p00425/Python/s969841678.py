def main():
    while True:
        N = int(input())
        if N == 0:
            return
        m = [1, 2, 3, 4, 5, 6]
        ans = 1
        for i in range(N):
            o = input()[0]
            if o == 'N':
                m = [m[1], m[5], m[2], m[3], m[0], m[4]]
            elif o == 'S':
                m = [m[4], m[0], m[2], m[3], m[5], m[1]]
            elif o == 'W':
                m = [m[2], m[1], m[5], m[0], m[4], m[3]]
            elif o == 'E':
                m = [m[3], m[1], m[0], m[5], m[4], m[2]]
            elif o == 'R':
                m = [m[0], m[2], m[4], m[1], m[3], m[5]]
            elif o == 'L':
                m = [m[0], m[3], m[1], m[4], m[2], m[5]]
            ans += m[0]

        print(ans)


if __name__ == '__main__':
    main()

