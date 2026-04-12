import sys
input = sys.stdin.readline


def read():
    X = int(input().strip())
    return X,


def solve(X):
    if X >= 30:
        return "Yes"
    else:
        return "No"


if __name__ == '__main__':
    inputs = read()
    outputs = solve(*inputs)
    if outputs is not None:
        print("%s" % str(outputs))
