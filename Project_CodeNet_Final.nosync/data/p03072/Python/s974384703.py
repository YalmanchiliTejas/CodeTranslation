n = int(input())
h_list = list(map(int,input().split()))
l = []
for i in range(n):
    if i == 0:
        l.append(h_list[i])
    else:
        if h_list[i] >= h_list[i-1] and h_list[i] >= max(l):
            l.append(h_list[i])
print(len(l))
