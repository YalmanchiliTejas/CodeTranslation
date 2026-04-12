def resolve():
    '''
    code here
    '''
    N = int(input())
    As = [int(item) for item in input().split()]

    memo = As[0]
    res = 0
    for i in range(N-1):
        res += (memo * As[i+1])%(10**9 + 7)
        memo += As[i+1]

    print(res % (10**9 + 7))


if __name__ == "__main__":
    resolve()
