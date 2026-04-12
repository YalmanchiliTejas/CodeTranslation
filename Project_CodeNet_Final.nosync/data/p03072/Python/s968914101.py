n = input()
x=0
mh = 0
for i in input().split():
    i = int(i)
    if i >= mh:
        x += 1
        mh = i

print(x)
