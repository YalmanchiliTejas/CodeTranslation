h,w = map(int,input().split())
A = []
for i in range(h) :
    a = list(input())
    if '#' in a :
        A.append(a)
h = len(A)

l = [0]*w
for i in range(h) :
    for j in range(w) :
        if A[i][j] == '.' :
            l[j]+= 1

for i in range(w) :
    if l[i] == h :
        for j in range(h) :
            A[j][i] = 0

for i in range(h) :
    aa = [i for i in A[i] if i != 0]
    ans = ''.join(aa)
    print(ans)
