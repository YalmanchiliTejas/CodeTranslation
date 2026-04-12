n=int(input())
H=list(map(int,input().split()))
c=0
max=0
for i in range(n):
    if H[i]>=max:
        c+=1
        max=H[i]
print(c)