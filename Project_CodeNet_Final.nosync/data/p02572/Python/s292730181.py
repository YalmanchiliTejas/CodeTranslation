# coding: utf-8
# 日本語を入力できるようにするために上記一文が必要


N = int(input())
A_input = list(map( int, input().split()))

j_sum = 0
for j in range(N):
        j_sum = j_sum + A_input[j]


sum = 0
for i in range(N - 1 ):
        j_sum = j_sum - A_input[i]
        sum = sum +  A_input[i] * j_sum

print(sum % (10**9 + 7) )