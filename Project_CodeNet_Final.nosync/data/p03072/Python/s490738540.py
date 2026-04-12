n = int(input())
a = [int(i) for i in input().split()] 
b = a[0]
count =1
for i in range(1,len(a)):
    if a[i] >= b:
        b = a[i]
        count += 1
print(count)
        