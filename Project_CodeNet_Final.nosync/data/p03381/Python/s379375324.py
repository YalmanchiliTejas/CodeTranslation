n=int(input())
A=list(map(int,input().split()))
S=sorted(A)
a=S[n//2-1]
b=S[n//2]
for i in A:
    if i<a:
        print(b)
    elif a==i: print(b)
    elif b==i: print(a)
    else:
        print(a)