n=int(input())
H=list(map(int, input().split()))

max_high=0
count=0

for i in range(n):
    if H[i]>=max_high:
        count+=1
        max_high=H[i]
print(count)