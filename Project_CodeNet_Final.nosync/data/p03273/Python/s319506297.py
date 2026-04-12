import numpy as np

data = input().split()

h = int(data[0])
w = int(data[1])

count = 0
# creating math
i = 0
math = []
while i < h:
    x = input()
    x = list(x)
    math.append(x)
    i += 1
math = np.array(math).reshape(h,w)


# row check

i = 0 # row
j = 0 # colum
while i < h:
    while j < w:
        if math[i][j] == ".":
            
            j += 1
            if j == w:
                math = np.delete(math,i,0)
                h = h-1
                i -=1
                
                
                
        else:
            break
    j = 0
    i += 1
i = 0
j = 0

# colum check

while j < w:
    while i < h:
        if math[i][j] == ".":
            
            i += 1
            if i == h:
                math = np.delete(math,j,1)
                w = w-1
                j -= 1
                
                
        else:
            break
    i = 0
    j += 1
i = 0
j = 0
while i < h:
    while j < w:
        print(*math[i][j],end = "")
        j += 1
    i += 1
    j = 0
    print()


    
    
