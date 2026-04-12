n = int(input())
j=0
p=0
for i in map(int,input().split()):
    if j <= i:
        p += 1
        j = i
print(p)