
def main():
    t = list(map(str, input().split()))
    n = int(''.join(t))
    ans = 'YES' if n % 4 == 0 else 'NO'
    print(ans)


if __name__ == '__main__':
    main()