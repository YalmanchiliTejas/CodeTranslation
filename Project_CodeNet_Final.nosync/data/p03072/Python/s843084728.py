n = int(input())
h = list(map(int,input().split()))
l = [h[0]]

for i in range(1,n):
    if l[-1] <= h[i]:
        l.append(h[i])

print(len(l))