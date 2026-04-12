n=int(input())
h=input().split()
hi=0
count=0
for i in range(n):
    if hi<=int(h[i]):
        hi=int(h[i])
        count+=1
print(count)