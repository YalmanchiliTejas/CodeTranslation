n = int(input())
h = [int(x) for x in input().split()]
h2 = []
for i in range(n):
    if h[i] == max(h[:i+1]):
        h2.append(h[i])
print(len(h2))