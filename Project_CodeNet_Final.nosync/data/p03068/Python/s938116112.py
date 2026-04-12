#coding:utf-8

N = int(input())
S = input()
K = int(input())

target = S[K-1]

result = ''
for string in S:
    if string == target:
        result += string
    else:
        result += '*'

print(result)
