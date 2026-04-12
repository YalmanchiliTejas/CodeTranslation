N = int(input())
H = list(map(int, input().split()))
l = [H[0]]
for i in H[1:]:
    if i >= max(l):
        l.append(i)
print(len(l))