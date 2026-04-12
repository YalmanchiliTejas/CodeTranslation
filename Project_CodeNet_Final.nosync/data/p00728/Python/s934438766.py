#-*- coding:utf-8 -*-


def judge(a,n):
    a.sort()
    del a[0]
    del a[-1]
    sum = 0
    for i in range(len(a)):
        sum += a[i]
    return int(sum / len(a))

while(1):
    n = int(input())
    if (n == 0):
        exit(0)
    else:
        a = [int(input()) for i in range(n)]
        print(judge(a,n))