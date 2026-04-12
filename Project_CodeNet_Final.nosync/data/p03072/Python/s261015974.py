n=int(input())
h_list=[int(i) for i in input().split()]
b = 1  # counter
c = 1  # answer
m = h_list[0]  # max height
while b != n:
    if h_list[b] >= m:
        m = h_list[b]
        c += 1
    b += 1
print(c)