n = input()    
m = n.split()
p = [int(i) for i in m]
if p[0] == p[1]:
    print("Yes")
else:
    print("No")