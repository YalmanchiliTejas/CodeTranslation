c = 0
n = int(input())
li = list(map(int,input().split()))
li1 = []
for a in li:
    li1.append(a)
    if a >= max(li1):
            c += 1
print(c)