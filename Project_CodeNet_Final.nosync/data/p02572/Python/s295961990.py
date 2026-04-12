

def read_int():
    return int(input().strip())


def read_ints():
    return list(map(int, input().strip().split(' ')))


def solve():
    N = read_int()
    A = read_ints()
    S = A[0]
    answer = 0
    modulo = 10**9+7
    for i in range(1, N):
        answer = (answer+A[i]*S)%modulo
        S = (S+A[i])%modulo
    return answer


if __name__ == '__main__':
    print(solve())
