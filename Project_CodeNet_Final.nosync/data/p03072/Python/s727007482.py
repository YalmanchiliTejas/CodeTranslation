n=int(input())
h=list(map(int,input().split()))
H=h[0]
count=0
for i in range(n):
    if H<=h[i]:
        count+=1
        H=h[i]
print(count)