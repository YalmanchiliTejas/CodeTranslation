n = int(input())
h = list(map(int,input().split()))	

count = 1
max = h[0]
f = 0
if n == 1:
    print(count)
    f = 1
else:
    for i in range(1,n):
        if h[i] >= max:
            count += 1
            max = h[i]
        
if f == 0:
    print(count)