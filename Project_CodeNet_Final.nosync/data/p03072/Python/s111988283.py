N=int(input())
H=list(map(int, input().split()))

max_value=H[0]

count=0
for h in H:
    if h>=max_value:
        count+=1
        max_value=h

print(count)