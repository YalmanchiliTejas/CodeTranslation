n = int(input())
H=map(int, input().split())
k=0
j=0
for num in H:
    if num>=k:
        j=j+1
        k=num
print(j)