N = int(input())
S = input()
K = int(input())
for i in S:print(i if i ==S[K-1] else '*',end='')