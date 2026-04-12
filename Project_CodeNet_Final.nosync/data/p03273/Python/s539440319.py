H,W = map(int, input().split(" "))

HW = [[]]*H
h=0
for _ in range(H):
    Low = input()
    if Low!="."*W:
        HW[h] = list(Low)
        h+=1
        
HW_T = list(zip(*HW[:h]))

hw_t = [[]]*W
w=0

for s in HW_T:
    col= str(''.join(s))
    if col!="."*h:
        hw_t[w] = list(col)
        w+=1

HW = list(zip(*hw_t[:w]))

for l in HW:
    s = str(''.join(l))
    print(s)