
def binSearch(S, x):
    a = -1
    b = len(S)-1

    while(a + 1 < b):
        c = (a+b)//2
        if S[c] >= x:
            a = c
        else:
            b = c

    return b

def main():
    N = int(input())
    A = [int(input()) for _ in range(N)]

    S = []

    for a in A:
        if len(S) == 0 or S[-1] >= a:
            S.append(a)
        else:
            p = binSearch(S, a)
            S[p] = a
    
    print(len(S))


if __name__ == '__main__':
    main()
