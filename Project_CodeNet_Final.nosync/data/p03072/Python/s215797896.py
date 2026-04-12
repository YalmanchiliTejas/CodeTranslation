n1 = int(input())
n2 = [int(i) for i in input().split()]

c1 = 0
for i1 in range(n1):
    if i1 == 0:
        c1 += 1
        continue
    if max(n2[0:i1]) <= n2[i1] :
        c1 += 1

print(c1) 