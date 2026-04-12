import sys
input = sys.stdin.readline


def main():
    H, W = [int(x) for x in input().split()]
    A = [input().strip() for _ in range(H)]

    ansh = []
    for i, a in enumerate(A):
        if a.count("#") == 0:
            ansh.append(i)

    answ = []
    for i, a in enumerate(zip(*A)):
        if a.count("#") == 0:
            answ.append(i)

    for j in range(H):
        if j in ansh:
            continue
        for i in range(W):
            if i in answ:
                continue
            else:
                print(A[j][i], end="")
        print("")

    
    
    


if __name__ == '__main__':
    main()

