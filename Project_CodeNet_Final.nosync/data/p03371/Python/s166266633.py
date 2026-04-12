import sys

input = sys.stdin.readline


def main():
    A, B, C, X, Y = [int(x) for x in input().split()]
    ans = []
    ans.append(A * X + B * Y)
    ans.append(C * 2 * (max(X, Y)))
    if X > Y:
        ans.append(C * 2 * Y + (X - Y) * A)
    else:
        ans.append(C * 2 * X + (Y - X) * B)

    print(min(ans))


    

if __name__ == '__main__':
    main()

