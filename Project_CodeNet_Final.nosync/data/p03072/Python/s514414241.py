N = int(input())
v = list(map(int , input().split()))
m = v[0]
count = 0
for i in v:
    if m <= i:
        count += 1
        m = i
print(count)