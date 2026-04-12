h,w= list(map(int, input().split()))
li=[list(input()) for _ in range(h)]
memo=0
for i in li:
    for j in i:
        if j=="#":
            memo+=1
if memo==h+w-1:
    print("Possible")
else:
    print("Impossible")