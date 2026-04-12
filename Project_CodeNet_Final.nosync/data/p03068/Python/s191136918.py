def main():
    n = int(input())
    S = input()
    k = S[int(input()) - 1]
    ans = [s if s == k else '*' for s in S]
    print(''.join(ans))

if __name__ == '__main__':
    main()
