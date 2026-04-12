from sys import stdin

def main():
    N = int(input())
    S = list(input())
    K = int(input())

    sk = S[K-1]
    for i, s in enumerate(S):
        if s != sk:
            S[i] = '*'
    print(''.join(S))

input = lambda: stdin.readline().rstrip()
main()
