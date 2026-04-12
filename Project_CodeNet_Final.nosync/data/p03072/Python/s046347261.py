N = int(input())
Hlist = tuple(map(int,input().split()))
counter = 0
for i,h in enumerate(Hlist,0):
    if h == max(Hlist[:i+1]):
        counter += 1

print(counter)