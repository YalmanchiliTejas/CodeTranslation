N = int(input())
H = [int(i) for i in input().split()] 

count = 1

for i in range(1, N):
    nn = 0
    A = H[:i+1]
    for j in A[:-1]:
        if j > A[-1]:
            nn += 1
    if nn==0:
        count += 1

print(count)