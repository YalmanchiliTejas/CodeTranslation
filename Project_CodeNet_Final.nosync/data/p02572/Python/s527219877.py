import sys


def input():
    return sys.stdin.readline().rstrip()

def main():

    mod =10**9+7
    N =int(input())
    A =list(map(int,input().split()))

    ss =sum(A) %mod
    sm =ss *ss % mod
    for i in A:
        sm -= i*i
        sm %=mod

    sm =sm*pow(2,mod-2,mod) %mod

    print(int(sm))










if __name__ == "__main__":
    main()
