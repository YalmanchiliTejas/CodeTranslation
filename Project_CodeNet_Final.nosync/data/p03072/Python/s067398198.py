n = int(input())
l = list(map(int, input().split()))
v, c = l[0], 0
for i in range(1,n):
    if v <= l[i]:
        v = l[i]; c += 1
print(c+1)