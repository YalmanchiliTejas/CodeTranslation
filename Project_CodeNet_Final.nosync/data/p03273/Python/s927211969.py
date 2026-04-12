A,B=[],[]
h,w=map(int,input().split())
for i in range(h):
    a=input()
    if "#" in a:
        A.append(a)
b=""
for i in range(w):
    if "#" not in b:
        B.append(i-1)
    b=""
    for j in range(len(A)):
        b+=A[j][i]
if "#" not in b:
    B.append(w-1)
B.pop(0)
o=0
for i in range(len(A)):
    o=0
    A[i]=list(A[i])
    for j in B:
        A[i].pop(j-o)
        if o==len(B)-1:
            print("".join(A[i]))
        o+=1
if len(B)==0:
    for i in A:
        print("".join(i))