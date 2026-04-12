n=int(input())

t = list(map(int,input().split()))

count = 0
mmax = 0

for i in t:
    if mmax <= i:
        mmax = i
        count += 1
print(count)