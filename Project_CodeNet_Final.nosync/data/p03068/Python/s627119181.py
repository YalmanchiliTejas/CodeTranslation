
def kari():
    N = list(map(int, input().split()))
    A, B = map(int, input().split())

def main():
    N = int(input())
    S = list(input())
    K = int(input())

    aaa = S[K - 1]

    for i in range(N):
        if S[i] != aaa:
            S[i] = '*'
    print(''.join(S))



if __name__ == '__main__':
    main()
