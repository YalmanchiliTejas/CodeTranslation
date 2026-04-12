n=int(input())
h=list(map(int,input().split()))

saidai = 0
count = 0
for i in range(n):
    if saidai <= h[i]:
        count = count+1
        saidai = h[i]
    else:
        continue
print(count)