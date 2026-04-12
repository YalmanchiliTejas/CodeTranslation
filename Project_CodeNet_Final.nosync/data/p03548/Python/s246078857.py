#B ISU
x,y,z = map(float,input().split())
x = x- z
d = y+z
k = 0
while x >= d:
    k =k+1
    x = x- d
    
print(k)
    
    