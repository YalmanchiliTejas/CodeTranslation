# coding: utf-8
import fractions
#N = int(input())

h, w = map(int,input().split())
h_list = []
w_list = []
F = []
for i in range(h):
    l = list(input())
    F.append(l)
    if list(set(l)) == ['.']:
        w_list.append(i)
        
for i in range(w):
    cnt = 0
    for j in range(h):
        if F[j][i] == '.':
            cnt += 1
        else:
            break
    if cnt == h:
        h_list.append(i)
A = []
#print(h_list,w_list)#ここまでOK
for i in range(h):
    if i not in w_list:
        l = []
        for j in range(w):
            if j not in h_list:
                #print(F[i][j])
                l.append(F[i][j])
        
        A.append(l)

for i in range(len(A)):
    print(''.join(A[i]))