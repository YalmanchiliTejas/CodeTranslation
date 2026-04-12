import numpy as np

H,W=map(int,input().split())
field=[list(input()) for i in range(H)]

field=[i for i in field if "#" in i]

field=np.array(field)
#print(field)

field=np.rot90(field,k=1)
field=field.tolist()

field=[i for i in field if "#" in i]

field=np.rot90(field,k=-1)
field=field.tolist()

#print(field)
for i in field:
    print("".join(i))