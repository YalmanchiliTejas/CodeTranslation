# -*- coding: utf-8 -*-

def main(N, A_list):
    total_list = []
    total = 0
    for i in range(len(A_list)):
        total += A_list[i]
        total_list.append(total)

    num = 0
    for i in range(len(A_list)-1):
        num += A_list[i] * (total_list[len(A_list)-1]-total_list[i])

    val = num % ((10 ** 9) + 7)
    print(val)


N = int(input())
A_list = list(map(int, input().split()))
main(N, A_list)
