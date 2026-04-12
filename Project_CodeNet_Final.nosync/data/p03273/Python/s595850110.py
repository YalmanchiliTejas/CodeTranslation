import sys


def input():
    return sys.stdin.readline().rstrip()


def main():
    H,W =map(int,input().split())
    A =[]
    h = []
    w = []
    count =0
    for i in range(H):
        a = list(str(input()))
        if a.count('#')==0:
            continue
        else:
            A.append(a)
            count +=1


    for j in range(W):
        for i in range(count):
            if A[i][j] =="#":
                break

            if i == count-1:
                w.append(j)

    for i in range(count):
        for j in range(W):
            if j not in w:
                print(A[i][j],sep="",end="")
        print("")







if __name__ == "__main__":
    main()
