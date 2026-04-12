def flatten_2d(data):
    for block in data:
        for elem in block:
            yield elem
            
h,w = map(int,input().split())

List=[input() for i in range(h)]

#print(List)

a = list(flatten_2d(List))

#print(list(flatten_2d(List)))


if a.count("#")==(h+w-1):
    print("Possible")
else:
    print("Impossible")