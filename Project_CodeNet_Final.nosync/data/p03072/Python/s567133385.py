N = int(input())
H = [int(x) for x in input().split()]
r = 1
hmax = H[0]
for i in range(1,len(H)):
    if (H[i] >= hmax):
        r += 1
        hmax = H[i]
print(r)