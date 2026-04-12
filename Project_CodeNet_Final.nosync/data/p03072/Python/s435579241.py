N = int(input())
ar =list( map(int, input().split()))

c = 1
maxc = ar[0]
for a in ar[1:]:
    if a >= maxc:
        c += 1
        maxc = a

print(c)
