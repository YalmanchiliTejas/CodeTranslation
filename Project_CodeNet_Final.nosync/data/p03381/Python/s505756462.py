n = int(input())
x = list(map(int, input().split()))
sorted_x = list(sorted(x))
l, r = sorted_x[len(x) // 2 - 1], sorted_x[len(x) // 2]

for i in x:
    print(r if i <= l else l)
