n = int(input())
data = list(map(int,input().split()))

m = -1

res = 0
for d in data:
    if d>=m:
        res+=1
    m = max(m,d)
print(res)
