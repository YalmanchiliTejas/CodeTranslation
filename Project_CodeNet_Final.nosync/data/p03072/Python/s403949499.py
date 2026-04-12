n = int(input())
H = list(map(int,input().split()))
maxi = 0
count = 0
for h in H:
    if h >= maxi:
        maxi = h
        count += 1
        
print(count)