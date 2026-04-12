n = int(input())
a = list(map(int,input().split()))
b = [0]*n
b[n//2] = a[0]
count = n//2
if n%2 == 0:
    for i in range(1,n):
        if i%2 == 1:
            count = count-i
        else:
            count = count+i
        b[count] = a[i]
else:
    for i in range(1,n):
        if i%2 == 1:
            count = count+i
        else:
            count = count-i
        b[count] = a[i]
print(*b)