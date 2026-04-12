N=int(input())
H=list(map(int,input().split()))
mx=H[0]
count=0
for i in H:
    if mx<=i:
        mx=i
        count+=1

print(count)