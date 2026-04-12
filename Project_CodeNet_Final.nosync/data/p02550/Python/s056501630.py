import sys

def main():
    N, X, M = map(int, sys.stdin.readline().rstrip().split())

    S = [0] * M  # 何回目に来たか
    C = [0] * M  # 最初にたどり着いたときの値

    _sum = 0
    cycle_sum = 0
    cycle_count = 0
    for i in range(1, N+1):
        _sum += X
        if S[X] == 0:
            C[X] = _sum
            S[X] = i
        else:
            cycle_sum = _sum - C[X]
            cycle_length = i - S[X]
            break
        X = X**2 % M
    else:
        print(_sum)
        return        

    # print(X, S[X], C[X], i, _sum)
    first_sum = C[X]
    cycle_n = (N - S[X]) // cycle_length
    _sum = first_sum + cycle_n * cycle_sum
    rest = N - (S[X] + cycle_n * cycle_length)
    # print(first_sum, cycle_length, cycle_sum, _sum, rest)
    # print(X, X**2  % M)

    for i in range(rest):
        X = X**2 % M
        _sum += X
    
    print(_sum)


main()

