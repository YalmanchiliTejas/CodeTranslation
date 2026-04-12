N = int(input())
ARR = list(map(int, input().split()))

def calculate(n, arr):
    mod = 1000000000 + 7
    result = 0

    rightTotal = sum(arr)
    for i in range(n-1):
        rightTotal -= arr[i]
        result += (arr[i] * rightTotal) % mod

    print(result % mod)




calculate(N, ARR)