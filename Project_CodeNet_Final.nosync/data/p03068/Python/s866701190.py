#coding:utf-8
n = int(input())
S = input()
k = int(input())
char = S[k-1]
S = [s if s == char else '*' for s in S]
print ("".join(S))
