import sys
input = sys.stdin.readline
BIG = 10**9 + 7

def sumpp(n,a):
    acc = 0
    tmp = 0
    sumv = sum(a)
    for i in range(n):
        tmp += a[i]
        acc += a[i] * (sumv - tmp)
    return acc % BIG

if __name__ == "__main__":
    n = int(input())
    a = list(map(int,input().split()))
    print(sumpp(n,a))
