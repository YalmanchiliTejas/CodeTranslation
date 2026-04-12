def main():
    N = int(input())
    while N != 0:
        s = [int(input()) for i in range(N)]
        s.sort()
        print(sum(s[1:N-1])//(N-2))
        N = int(input())
if __name__ == '__main__':
    main()
