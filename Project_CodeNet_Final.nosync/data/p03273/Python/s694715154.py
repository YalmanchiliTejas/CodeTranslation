h,w=map(int,input().split())
A=[]
for i in range(h):
    a=list(input())
    if "#" in a:
        A.append(a)
    else:
        h-=1

num=[]
for i in range(w):
    for j in range(h):
        if A[j][i]=="#":
            num.append(i)
            break
for i in range(h):
    for j in num:
        print(A[i][j],end="")
    print()
