n = int(input())
l = [int(x) for x in input().split()]
max_h = l[0]
result = 1
for i in range(1,n):
    if max_h <= l[i]:
        result += 1
        max_h = l[i]
    else:
        continue
print(result)