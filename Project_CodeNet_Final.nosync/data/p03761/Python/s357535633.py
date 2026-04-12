n=int(input())
S=[input() for _ in range(n)]
abc='abcdefghijklmnopqrstuvwxyz'
A=[]
for i in range(len(abc)):
    min=float('inf')
    for j in range(n):
        if min>S[j].count(abc[i]):
            min=S[j].count(abc[i])
    A.append(min)
for i in range(len(A)):
    if A[i]:
        for j in range(A[i]):
            print(abc[i], end='')
if all(x==0 for x in A):
    print('')
