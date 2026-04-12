H,W=map(int,input().split())
A=[input()for i in range(H)]
for i in range(H):
    A[i]=A[i]+"."
A.append("."*(W+1))
p,q=1,1
c=1
t=0
for i in A:
    t+=i.count("#")
if t!=H+W-1:
    c=0
for i in range(H+W-2):
    if A[p-1][q-1]==".":
        c=0
        break
    if A[p][q-1]=="." and A[p-1][q]=="#":
        q+=1
    elif A[p][q-1]=="#" and A[p-1][q]==".":
        p+=1
    else:
        c=0
        break
print("Possible" if c else "Impossible")