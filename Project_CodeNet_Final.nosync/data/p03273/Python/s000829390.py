# coding: utf-8

h, w = map(int,input().split())
A = []

for i in range(h):
    l = list(input())
    if list(set(l)) == ['.']:
        h -= 1
    else:
        A.append(l)
#for a in A:
    #print(a)
Ans = []
for i in range(w):
    cnt = 0
    for j in range(h):
        if A[j][i] == '.':
            cnt += 1
    if cnt == h:
        Ans.append(i)

for i in Ans:
    for j in range(h):
        A[j][i] = ''

for a in A:
    print(''.join(a))