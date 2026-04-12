n = int(input())
out = [0 for x in range(n)]
inp = [int(x) for x in input().split(' ')]
if n%2==0:
    for i in range(n):
        if i % 2 == 0:
            out[int(n/2) + int(i/2)] = inp[i]
        else:
            out[int(n/2) - int((i+1)/2)] = inp[i]
else:
    k = int((n-1)/2)
    for i in range(n):
        if i % 2 == 0:
            out[k - int(i/2)] = inp[i]
        else:
            out[k+int((i+1)/2)] = inp[i]
for i in out:
    print(i, end=' ')
