a,b,c=[int(i) for i in input().split()]
s=0
i=0
while s<=a-2*c:
    i=i+1
    s=b*i+c*(i-1)

print(i-1)