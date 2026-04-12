#ABC078 B - ISU
x,y,z = map(int,input().split())

l = y + 2*z
i = 1
while l + y + z <= x:
    l += y + z
    i += 1
print(i)