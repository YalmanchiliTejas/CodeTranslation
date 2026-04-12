n = int(input())
h = [int(i) for i in input().split()]
ma = -1
c = 0
for i in h:
    if ma <= i:
        ma = i
        c+=1
print(c)
