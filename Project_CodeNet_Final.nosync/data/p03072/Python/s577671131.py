N=int(input())
H = list(map(int,input().split()))
max=H[0]
count=0

for i in H:
    if i>=max:
        max=i
        count=count+1

print(count)