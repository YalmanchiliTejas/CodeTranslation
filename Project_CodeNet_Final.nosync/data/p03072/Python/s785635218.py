N = int(input())
H = list(map(int, input().split()))

h_list = []
count = 0
for h in H:
    h_list.append(h)
    h_max = max(h_list)
    if h >= h_max:
        count += 1
print(count)