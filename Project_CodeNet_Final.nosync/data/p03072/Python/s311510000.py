N = int(input())
H = [int(i) for i in input().split()]

h = H[0]
c = 1
for i in H[1:]:
    if h <= i:
        c +=1 
        h = i
print(c)