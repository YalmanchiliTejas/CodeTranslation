n=input()
a=map(int,raw_input().split())
count=1
b=0
for i in range(1,n):
    j=1
    while b >= 0 and i!=j-1:
        if a[i]>=a[i-j]:
            j+=1
        else:
            break
        if i==j-1 :
            count+=1
print(count)
