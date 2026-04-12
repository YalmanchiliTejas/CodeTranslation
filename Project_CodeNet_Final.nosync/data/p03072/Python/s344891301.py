n = int(input())
h = list(map(int, input().split()))

s = 0
a = 0
for i in h:
    if i >= a:
        a = i
        s +=1

print(s)