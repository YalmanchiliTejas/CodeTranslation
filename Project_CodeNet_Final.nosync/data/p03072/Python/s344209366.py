a=int(input())
ct=1
list1=list(map(int,input().split()))
b=list1[0]
for i in range(1,a):
    if b<=list1[i]:
        ct+=1
        b=list1[i]
print(ct)