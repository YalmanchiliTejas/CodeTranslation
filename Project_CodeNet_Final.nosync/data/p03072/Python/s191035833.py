n = int(input())
l = [int(i) for i in input().split()]

v = 0


for i in range(len(l)-1,-1,-1):
    j = 0
    nosee = False 
    for j in range(i):
        if(l[i]<l[j]):
            nosee = True
            break
    if(not(nosee)):
        v+=1
print(v)
