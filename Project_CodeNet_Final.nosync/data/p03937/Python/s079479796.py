H,W=map(int,input().split())
A=[input() for i in range(H)]
count=0
for a in A:
    count+=a.count("#")
if count==H+W-1:
    print("Possible")
else:
    print("Impossible")