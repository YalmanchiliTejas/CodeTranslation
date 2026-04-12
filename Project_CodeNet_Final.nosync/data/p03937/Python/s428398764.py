
h,w = map(int,input().split())
a = []
count = 0

for i in range(h):
    a.append(list(map(str,input().split())))

for j in range(h):
    c = str(a[j])
#    print(c)
    count += c.count("#")
#    print(count)

if count == h + w -1:
    print("Possible")
else:
    print("Impossible")
