#coding:utf-8

N = int(input())
S = input()
K = int(input())

base = S[K-1]
new = []

for i in range(N):
    if S[i] != base:
        new.append('*')
    else:
        new.append(base)

ans = ''.join(new)
print(ans)