N = int(input())
A = list(map(int,input().split()))
m = 0
c = 0
for i in A:
    if m <= i:
        c += 1
        m = i

print(c)