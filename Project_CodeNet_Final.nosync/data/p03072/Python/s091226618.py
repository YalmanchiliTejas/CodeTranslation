n=int(input())
*h,=map(int,input().split())
c=0
for i in range(n):
    if all(h[i]>=h[j] for j in range(i)):
        c+=1
print(c)