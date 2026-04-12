A,B=list(map(int,input().split()))
l=[]
for i in range(A):
   l.append(list(input()))
c=0
for i in range(A):
   c+=l[i].count("#")
print("Possible" if A+B-1 == c else "Impossible")