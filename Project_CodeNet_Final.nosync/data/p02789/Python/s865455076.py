import sys


# N, M = map(int, input().split())
# nums = list(map(int, input().split()))
# nums_2d = [list(map(int, input().split())) for _ in range(N)]


def main():
    N, M = map(int, input().split())
    if M >= N:
        ans = 'Yes'
    else:
        ans = 'No'

    print(ans)


if __name__ == '__main__':
    main()
