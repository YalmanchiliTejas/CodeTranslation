n=int(input())
a=input().split()
s=0
num=0
#print(a)
for i in range(n):
    if int(a[i])>=s:
        num+=1
        s=int(a[i])
print(num)