import numpy as np


def main():
    n = int(input())
    As = list(map(int, input().split()))
    mod = 10 ** 9 + 7

    As_sum = sum(As)
    ans = 0

    for i in range(n):
        As_sum -= As[i]
        ans += As_sum * As[i]
        ans %= mod
    ans %= mod
    print(ans)



if __name__ == "__main__":
    main()
