def read():
    N, M = list(map(int, input().strip().split()))
    return N, M

def solve(N, M):
    return 'Yes' if N == M else 'No'


if __name__ == '__main__':
    inputs = read()
    print("%s" % solve(*inputs))
