n = int(input())
h = list(map(int, input().split()))
l = [str(h[0])]
for i in h[1:]:
        if i>=int(sorted(l)[-1]):
            i = str(i)
            l.append(i)
print(len(l))