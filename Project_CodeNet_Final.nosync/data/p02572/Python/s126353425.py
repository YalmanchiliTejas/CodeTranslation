nn = int(input())
aa = list(map(int, input().split()))
bb = [0]*(nn-1)
mysum = sum(aa)
mydiff = 0

for i in range(1,nn):
    mydiff += aa[i - 1]
    bb[i-1] = mysum - mydiff

finalsum = 0
for i in range(nn-1):
        finalsum += aa[i]*bb[i]
        finalsum = finalsum % (10**9 + 7)

print(finalsum)