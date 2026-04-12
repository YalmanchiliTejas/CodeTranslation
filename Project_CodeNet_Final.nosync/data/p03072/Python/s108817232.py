n = int(input())
summit=[int(i) for i in input().split()]
#print(List)
max = summit[0]
sum = 1
for i in range(n-1):
    if max <= summit[i+1]:
        #print(max,summit[i+1])
        max = summit[i+1]
        sum = sum + 1
print(sum)
