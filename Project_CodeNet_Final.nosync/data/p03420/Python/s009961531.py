
def read_int():
    return int(input().strip())


def read_ints():
    return list(map(int, input().strip().split(' ')))


def solve():
    N, K = read_ints()
    answer = 0
    if K == 0:
        return N*N
    for b in range(K+1, N+1):
        answer += (N//b)*(b-K)+max(0, N%b-(K)+1)
    return answer


if __name__ == '__main__':
    print(solve())
