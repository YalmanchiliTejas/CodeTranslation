H,W=map(int,input().split())
A = []
for _ in range(H):
    a = input()
    A.append(a)
count=0
for val in A:
    for query in val:
        if query=="#":
            count +=1
if count == H+W-1:
    print("Possible")
else:
    print("Impossible")