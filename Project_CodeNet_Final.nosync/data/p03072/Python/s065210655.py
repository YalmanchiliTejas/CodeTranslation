n = int(input())
a = list(map(int, input().split()))
b=0
c=0
for i in a:
    b = max(b,i)
    if i>=b:
        c += 1
print(c)