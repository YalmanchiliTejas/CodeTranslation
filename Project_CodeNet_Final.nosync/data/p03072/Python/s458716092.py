n = int(input())

l = [int(i) for i in input().split()]

num = l[0]
ct = 1
for i in range(1,n):
    if l[i] >= num:
        ct +=1
    num = max(num,l[i])
    
print(ct)