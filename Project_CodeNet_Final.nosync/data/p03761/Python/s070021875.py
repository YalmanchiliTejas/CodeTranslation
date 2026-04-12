import sys
from string import ascii_lowercase as a2z

input = sys.stdin.readline


def main():
    N = int(input())
    S = [""] * N
    for i in range(N):
        S[i] = input().rstrip()

    count = {}
    for al in a2z:
        count[al] = 50

    for s in S:
        for al in a2z:
            num = s.count(al)
            if num < count[al]:
                count[al] = num

    ans = ""
    for k, v in count.items():
        ans = "".join([ans, k * v])
    ans = "".join(sorted(ans))
    print(ans)


if __name__ == "__main__":
    main()
