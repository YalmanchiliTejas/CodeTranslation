N, *L,  = [list(map(int, s.split())) for s in open(0)]
N = N[0]
L = L[0]
num_view = 1
for i in range(1, N):
    not_view = 0
    for j in range(0, i):
        if L[i] < L[j]:
            not_view += 1
            
    if not not_view:
        num_view += 1
print(num_view)