n = int(input())
a = list(map(int , input().split()))
mx = 0
I = a[0]
for i in range(1,n):
        if(a[i] >= I):
            mx += 1
            I = a[i]
print(mx + 1)
