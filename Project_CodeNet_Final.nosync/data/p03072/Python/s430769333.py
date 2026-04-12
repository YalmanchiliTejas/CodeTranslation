n = int(input())
h = [int(x) for x in input().split()]
max= 0
count=0
for i in range(0,n):
    if h[i]>=max:
        max = h[i]
        count+=1
print(count)