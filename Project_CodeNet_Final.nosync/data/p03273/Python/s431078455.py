h,w = map(int,input().split())
a = [[i for i in input()] for j in range(h)]
b = [a[i] for i in range(h) if "#" in a[i]]
#print(b)
t = [i for i in zip(*b)]
c = zip(*[i for i in t if "#" in i])
for d in c:
    print("".join(d))
