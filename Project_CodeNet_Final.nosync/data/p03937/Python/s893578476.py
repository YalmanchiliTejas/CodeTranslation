H,W=map(int,input().split())
A= [list(input()) for _ in range(H)]
cnt=0
for p in A:
    for q in p:
        if q=="#":
            cnt +=1

if cnt == H+W-1:
    print("Possible")
else:
    print("Impossible")