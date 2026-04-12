h , w = map(int, input().split())
A = []
for i in range(h):
    A.append(list(input()))
#行に対しての作業
ans = 0
'''
for i in A:
    print(A.index)
    if(i.count('.') == w):
        del A[A.index(i)]   
'''
B = []
for i in range(h):
    if(A[i].count('.') != w):
        B.append(A[i])


count=0
ans=0
for i in range(w):
    i -=ans
    for j in B:
        if(j[i] == '.'):
            count+=1
    if(count==len(B)):
        for j in B:
            del j[i]
        ans +=1
    count=0

for i in B:
    for j in i:
        print(j, end="")
    print()