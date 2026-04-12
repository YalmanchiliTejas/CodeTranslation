input()
H = [int(x) for x in input().split()]

h, N = H[0], 1
for h_i in H[1:]:
    if h_i >= h:
        N += 1
        h = h_i
print(N)
