h, w = map(int,input().split())
a = [list(input()) for _ in range(h)]
c = 0
for p in a :
    for q in p:
        if q=="#":
            c +=1
 
if c == h + w - 1:
    print("Possible")
else:
    print("Impossible")