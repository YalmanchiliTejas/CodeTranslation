import sys
l1 = input().split()
l2 = []
for num in l1:
    l2.append(int(num))
value = []
for c in range(0,2*max([l2[3],l2[4]])+1,2):
    a = max([l2[3]-(c/2),0])
    b = max([l2[4]-(c/2),0])                    
    value.append(int((a*l2[0])+(b*l2[1])+(c*l2[2    ])))
print(min(value))
