n = int(input())
l = list(map(int, input().split(' ')))
sorted_l = sorted(l)

base = int((n + 1) // 2) - 1
median = sorted_l[base]
for i in l:
    if i <= median:
        print(sorted_l[base + 1])
    else:
        print(sorted_l[base])
