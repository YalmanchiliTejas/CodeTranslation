N = int(input())
A = sorted([int(input()) for i in range(N)])

a = [0] * N
b = [0] * N
j = 1

for i in range(N-1):    
    a[i] += -j
    a[i+1] += j
    b[i] += j
    b[i+1] += -j    
    j = -j

a.sort()
b.sort()
s1 = sum([i*j for i,j in zip(a, A)])
s2 = sum([i*j for i,j in zip(b, A)])
print(max(s1,s2))