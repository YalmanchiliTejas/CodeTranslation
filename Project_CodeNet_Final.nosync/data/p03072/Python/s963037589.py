n = int(input())
a = list(map(int,input().split()))
c = a[0]
k = 1
for i in range(1,len(a)):
    if(a[i]>=c):
        k+=1
        c = a[i]
print(k)
