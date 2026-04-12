import sys


def input():
    return sys.stdin.readline().rstrip()


def main():

    N =int(input())
    H =list(map(int,input().split()))
    count =1
    hiest =H[0]
    for i in range(1,N):
        if hiest <=H[i]:
            count +=1
            hiest =H[i]

    print(count)

if __name__ == "__main__":
    main()
