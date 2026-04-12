h, w = map(int, input().split())
a = []
for _ in range(h):
    a.append(input())
    
sharpnum = 0
for ai in a:
    sharpnum += ai.count("#")
     
                
if sharpnum == (h+w - 1):
    print("Possible")
else:
    print("Impossible")