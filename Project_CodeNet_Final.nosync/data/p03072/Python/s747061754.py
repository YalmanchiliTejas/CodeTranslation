#Coding-Utf-8

N=int(input())
H=list(map(int, input().split()))
count=1
Num= H[0]

for i in range(1,N):
    if H[i]>=Num:
        count+=1
        Num=H[i]

print(count)
