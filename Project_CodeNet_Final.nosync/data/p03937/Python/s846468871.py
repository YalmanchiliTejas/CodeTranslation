import sys

h,w=map(int,input().split())
m=[list(input()) for _ in range(h)]

s=[]

i_b,j_b=0,0
for i in range(h):
    for j in range(w):
        if m[i][j] =="#":
            if i<i_b or j<j_b:
                print("Impossible")
                sys.exit()
            else:
                i_b,j_b=i,j
print("Possible")