import sys

def main():
    input = sys.stdin.read()
    data = list(map(int, input.split()))

    n = data[0]
    data = data[1:]

    sum = 0
    for i in data:
        sum += i
    ans, cnt = 0, 0

    for i in data:
        # cnt += i
        sum -= i
        ans += sum * i
        ans = ans % 1000000007
        # print(ans,sum)
    print(ans)


if __name__ == '__main__':
    main()
