# coding: utf-8
# Your code here!
a= input()
a = list(map(int, input().split()))

c=0


for i in range(0,len(a)):
    flag=True
    for j in range(0,i):
        #rint(a[j],a[i])
        if a[j]>a[i]:
            flag=False
    if flag:
        c+=1
print(c)
    