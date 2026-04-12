n = int(input())
h = [int(i) for i in input().split()]
max = h[0]
c = 1
for i in range(n-1):
    if h[i+1]>=max:
        c+=1
        max=h[i+1]
print(c)
