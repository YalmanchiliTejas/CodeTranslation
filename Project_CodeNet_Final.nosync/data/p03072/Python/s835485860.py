n=int(input())
p=input().split()
k=[]
for i in p:k.append(int(i))
c=1
for i in range(1,n):
    if i == 1:
        if k[1] >= k[0]:
            c+=1
        continue
    m=max(k[0:i])
    w=k[i]
    if m <= w:c+=1
print(c)