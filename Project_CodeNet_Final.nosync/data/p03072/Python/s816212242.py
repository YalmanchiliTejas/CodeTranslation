N = int(input())
H = list(map(int, input().split()))  

previous=0
count=0

for i in H:
    if previous<=i:
        previous=i
        count+=1

print(count)