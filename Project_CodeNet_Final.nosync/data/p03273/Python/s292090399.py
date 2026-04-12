import sys
def input():
    return sys.stdin.readline()[:-1]
H,W=map(int,input().split())
a=[input() for i in range(H)]
l=[0]*W
for i in a:
    for j in range(W):
        if i[j]=="#":
            l[j]+=1
for i in a:
    if "#" in i:
        for j in range(W):
            if l[j]:
                print(i[j],end="")
        print()